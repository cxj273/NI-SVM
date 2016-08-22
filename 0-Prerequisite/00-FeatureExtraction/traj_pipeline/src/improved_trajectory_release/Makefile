# set the binaries that have to be built
TARGETS := DenseTrackStab Video

# set the build configuration set 
BUILD := release
#BUILD := debug

# set bin and build dirs
BUILDDIR := .build_$(BUILD)
BINDIR := $(BUILD)

# libraries 
LDLIBS = $(addprefix -l, $(LIBS) $(LIBS_$(notdir $*)))
LIBS := \
	opencv_nonfree opencv_features2d opencv_flann opencv_calib3d opencv_highgui opencv_imgproc opencv_core \
        avdevice avformat avcodec avutil swscale z bz2 pthread rt
	#opencv_core opencv_highgui opencv_video opencv_imgproc opencv_calib3d opencv_features2d opencv_nonfree \
	avformat avdevice avutil avcodec swscale

# set some flags and compiler/linker specific commands
CXXFLAGS = -pipe -D __STDC_CONSTANT_MACROS -D STD=std -Wall $(CXXFLAGS_$(BUILD)) -I. -I/opt/include# -I/usr/users/0/iyu2/base/include -static
CXXFLAGS_debug := -ggdb
CXXFLAGS_release := -O3 -DNDEBUG -ggdb
LDFLAGS = -L/opt/lib -pipe -Wall $(LDFLAGS_$(BUILD))# -L/usr/users/0/iyu2/base/lib -static
LDFLAGS_debug := -ggdb
LDFLAGS_release := -O3 -ggdb

include make/generic.mk
