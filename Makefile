#
# Rooky Makefile
#
# project(Rooky)

# All project dirs
source_dir = Source
core_dir = Core
ghi_dir = GHI
kernel_dir = Kernel
manager_dir = Manager
material_dir = Material
math_dir = Math
number_dir = Number
platform_dir = Platform
policy_dir = Policy
stage_dir = Stage
utility_dir = Utility

# Find all sub source

core_source = $(wildcard $(source_dir)/$(core_dir)/*.cpp)
core_ghi_source = $(wildcard $(source_dir)/$(core_dir)/$(ghi_dir)/*.cpp)
core_kernel_source = $(wildcard $(source_dir)/$(core_dir)/$(kernel_dir)/*.cpp)
core_kernel_source = $(wildcard $(source_dir)/$(core_dir)/$(kernel_dir)/*.cpp)

sub_dirs = $(shell find $(source_dir) -type d)

PHONY : all

all:
	@echo $(sub_dirs)
