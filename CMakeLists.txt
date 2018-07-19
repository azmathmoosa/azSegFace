
cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.  We call this the "examples" project.
project(azSegFace)


# Tell cmake we will need dlib.  This command will pull in dlib and compile it
# into your project.  Note that you don't need to compile or install dlib.  All
# cmake needs is the dlib source code folder and it will take care of everything.
add_subdirectory(dlib-19.15 dlib_build)


# To compile this program all you need to do is ask cmake.  You would type
# these commands from within the directory containing this CMakeLists.txt
# file:
#   mkdir build
#   cd build
#   cmake ..
#   cmake --build . --config Release
#
# The cmake .. command looks in the parent folder for a file named
# CMakeLists.txt, reads it, and sets up everything needed to build program.
# Also, note that CMake can generate Visual Studio or XCode project files.  So
# if instead you had written:
#   cd build
#   cmake .. -G Xcode
#
# You would be able to open the resulting Xcode project and compile and edit
# the example programs within the Xcode IDE.  CMake can generate a lot of
# different types of IDE projects.  Run the cmake -h command to see a list of
# arguments to -G to see what kinds of projects cmake can generate for you.  It
# probably includes your favorite IDE in the list.



#################################################################################
#################################################################################
#  A CMakeLists.txt file can compile more than just one program.  So below we
#  tell it to compile the other dlib example programs using pretty much the
#  same CMake commands we used above.
#################################################################################
#################################################################################


# I'm going to use a macro to simplify this
# CMakeLists.txt file.  However, usually you will create only one executable in
# your cmake projects and use the syntax shown above.
macro(add_example name)
   add_executable(${name} ${name}.cpp)
   target_link_libraries(${name} dlib::dlib )
endmacro()

# if an example requires GUI, call this macro to check DLIB_NO_GUI_SUPPORT to include or exclude
macro(add_gui_example name)
   if (DLIB_NO_GUI_SUPPORT)
      message("No GUI support, so we won't build the ${name} example.")
   else()
      add_example(${name})
   endif()
endmacro()

# The deep learning toolkit requires a compiler with essentially complete C++11
# support.  However, versions of Visual Studio prior to October 2016 didn't
# provide enough C++11 support to compile the DNN tooling, but were good enough
# to compile the rest of dlib.  So new versions of Visual Studio 2015 will
# work.  However, Visual Studio 2017 had some C++11 support regressions, so it
# wasn't until December 2017 that Visual Studio 2017 had good enough C++11
# support to compile the DNN examples.  So if you are using Visual Studio, make
# sure you have an updated version if you want to compile the DNN code.
#
# Also note that Visual Studio users should give the -T host=x64 option so that
# CMake will instruct Visual Studio to use its 64bit toolchain.  If you don't
# do this then by default Visual Studio uses a 32bit toolchain, WHICH RESTRICTS
# THE COMPILER TO ONLY 2GB OF RAM, causing it to run out of RAM and crash when
# compiling some of the DNN examples.  So generate your project with a statement
# like this:
#   cmake .. -G "Visual Studio 14 2015 Win64" -T host=x64 
if (NOT USING_OLD_VISUAL_STUDIO_COMPILER)
   add_gui_example(dnn_semantic_segmentation_ex)
   add_example(dnn_semantic_face_train_ex)
   add_executable(dnn_semantic_face_ex dnn_semantic_face_ex.cpp dnn_semantic_segmentation_net.cpp)
   target_link_libraries(dnn_semantic_face_ex dlib::dlib )
   add_example(dnn_semantic_segmentation_train_ex)
endif()



