#
# Rooky Makefile
#
# project(Rooky)

TARGET = Debug/Rooky
CC = g++
DFLAGS = -MM
CFLAGS = -g -c
RM = -rm
LIBS = -lvulkan -lxcb -lpng -lGLU -lGL -lGLEW -lopenal -lSOIL

# All project dirs
OUT_DIR = Debug
SOURCE_DIR = Source
DEBUG_DIR = Debug
RELEASE_DIR = Release
DEPEND_FILE = $(OUT_DIR)/.depend

# Tags
PHONY : clean debug release FORCE
FORCE:
# Find all sub DIR
SOURCE_SUB_DIRS = $(shell find $(SOURCE_DIR) -type d)
VPATH = SOURCE_SUB_DIRS
vpath %.h SOURCE_SUB_DIRS
SOURCE_FILES += $(foreach var, $(SOURCE_SUB_DIRS), $(wildcard $(var)/*.cpp))
INCLUDE_DIRS += $(foreach var, $(SOURCE_SUB_DIRS), -I$(var))

DEBUG_SUB_DIRS += $(subst Source, Debug, $(SOURCE_SUB_DIRS))
DEBUG_OBJECTS += $(subst Source, Debug, $(SOURCE_FILES:%.cpp=%.o))
DEBUG_DEPEND_FILES += $(DEBUG_OBJECTS:%.o=%.d)

RELEASE_SUB_DIRS = $(subst Source, Release, $(SOURCE_SUB_DIRS))
RELEASE_OBJECTS = $(subst Source, Release, $(SOURCE_FILES:%.cpp=%.o))
RELEASE_DEPEND_FILES = $(RELEASE_OBJECTS:%.o=%.d)

all :
#	@echo $(SOURCE_FILES)
	@echo $(DEBUG_OBJECTS)
	@echo $(DEBUG_DEPEND_FILES)

# Make Dir Function
MAKE_DIR = mkdir
MAKE_FLAGS = -p

debug_dir :
	@$(MAKE_DIR) $(MAKE_FLAGS) $(DEBUG_SUB_DIRS)

release_dir :
	@$(MAKE_DIR) $(MAKE_FLAGS) $(RELEASE_SUB_DIRS)

# Create Project DIR
debug : OUT_DIR = Debug
debug : debug_dir depend_build $(TARGET)
	@echo "Debug Build..."

#$(DEBUG_OBJECTS) : %.o : %.d
#	@echo "O : $@ form $<"

$(OUT_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@echo "O CPP : $@ form $<"
	$(CC) $(CFLAGS) -DVK_USE_PLATFORM_XCB_KHR $(INCLUDE_DIRS)  $< -o $@

$(TARGET) : $(DEBUG_OBJECTS)
	@echo "Build Debug/Rooky"
	$(CC) $(DEBUG_OBJECTS) $(LIBS) -o $(TARGET)

depend_build: $(SOURCE_FILES)
	$(RM) $(DEPEND_FILE)
	$(CC) $(INCLUDE_DIRS) $^ $(DFLAGS) >> $(DEPEND_FILE)

include $(DEPEND_FILE)

#$(OUT_DIR)/%.d : $(SOURCE_DIR)/%.cpp
#	@echo "D : $@ form $<"
#	@$(CC) $(DFLAGS) $(INCLUDE_DIRS) $< -o $@
#	$(CC) $(DFLAGS) $(INCLUDE_DIRS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; $(RM) $@.$$$$

#debug_depend : $(DEBUG_DEPEND_FILES)
#	@echo "Make Depend Files..."

#-include $(DEBUG_DEPEND_FILES)

release : release_dir
	@echo "Release Build..."

release_rooky : OUT_DIR = Release
release_rooky : $(RELEASE_OBJECTS)
	@echo "Build Release/Rooky"

# Process
clean :
	@echo "Clear Project..."
	$(RM) -rf $(DEBUG_DEPEND_FILES)
	$(RM) -rf $(DEBUG_OBJECTS)
	@echo "Clear Project Done !"

