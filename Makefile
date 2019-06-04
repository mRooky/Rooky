#
# Rooky Makefile
#
# project(Rooky)

TARGET = Debug/Rooky
CC = g++
DFLAGS = -MM
CFLAGS = -g -c -Wall
RM = -rm
LIBS = -lvulkan -lxcb -lpng -lGLU -lGL -lGLEW -lopenal -lSOIL
MACROS = -DVK_USE_PLATFORM_XCB_KHR
# All project dirs
OUT_DIR = Debug
SOURCE_DIR = Source
DEBUG_DIR = Debug
RELEASE_DIR = Release

# Tags
PHONY : clean debug release FORCE
FORCE:
# Find all sub DIR
SOURCE_SUB_DIRS = $(shell find $(SOURCE_DIR) -type d)
VPATH = SOURCE_SUB_DIRS
vpath %.h SOURCE_SUB_DIRS
SOURCE_FILES += $(foreach var, $(SOURCE_SUB_DIRS), $(wildcard $(var)/*.cpp))
INCLUDE_DIRS += $(foreach var, $(SOURCE_SUB_DIRS), -I$(var))

DEBUG_SUB_DIRS += $(subst Source/, Debug/, $(SOURCE_SUB_DIRS))
DEBUG_OBJECTS += $(subst Source/, Debug/, $(SOURCE_FILES:%.cpp=%.o))
DEBUG_DEPEND_FILES += $(DEBUG_OBJECTS:%.o=%.d)

RELEASE_SUB_DIRS = $(subst Source/, Release/, $(SOURCE_SUB_DIRS))
RELEASE_OBJECTS = $(subst Source/, Release/, $(SOURCE_FILES:%.cpp=%.o))
RELEASE_DEPEND_FILES = $(RELEASE_OBJECTS:%.o=%.d)

# Make Dir Function
MAKE_DIR = mkdir
MAKE_FLAGS = -p

################ TEST ################
test :
	@echo $(SOURCE_FILES)
	@echo $(DEBUG_OBJECTS)
	@echo $(DEBUG_DEPEND_FILES)

################ DEBUG ################
# Create Project DIR
debug : OUT_DIR = Debug
debug : debug_depend $(TARGET)

# Make object
%.o : %.d
	@echo "OBJ : $@ form $(subst Debug/, Source/, $(<:%.d=%.cpp))"
	@$(CC) $(CFLAGS) $(MACROS) $(INCLUDE_DIRS)  $(subst Debug/, Source/, $(<:%.d=%.cpp)) -o $@

# Build target
$(TARGET) : $(DEBUG_OBJECTS)
	@echo "Build Debug/Rooky"
	@$(CC) $(DEBUG_OBJECTS) $(LIBS) -o $(TARGET)

# Make depend
$(OUT_DIR)/%.d : $(SOURCE_DIR)/%.cpp
	@echo "DEP : $@ form $<"
	@$(MAKE_DIR) $(MAKE_FLAGS) $(dir $@)
	@$(CC) $(DFLAGS) $(INCLUDE_DIRS) -MT $@ -MT $(@:%.d=%.o) $< -MM -MF $@

# Depend flag
debug_depend : $(DEBUG_DEPEND_FILES)

# Update context
-include $(DEBUG_DEPEND_FILES)

################# RELEASE ###############
release_dir :
	@$(MAKE_DIR) $(MAKE_FLAGS) $(RELEASE_SUB_DIRS)

release : release_dir
	@echo "Release Build..."

release_rooky : OUT_DIR = Release
release_rooky : $(RELEASE_OBJECTS)
	@echo "Build Release/Rooky"

################ CLEAN ################
clean :
	@echo "Clear Project..."
	$(RM) -rf $(DEBUG_DEPEND_FILES)
	$(RM) -rf $(DEBUG_OBJECTS)
	$(RM) -rf $(TARGET)
	@echo "Clear Project Done !"

