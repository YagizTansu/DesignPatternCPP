# CMakeList.txt : CMake project for DesignPatternCPP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPatternCPP")

# Add source to this project's executable.
add_executable (DesignPatternCPP   "CommandPatternExample/CalculatorCommandExample.cpp" )
add_executable (DesignPatternCPP_command   "CommandPatternExample/CalculatorCommandExample.cpp"  )
add_executable (DesignPatternCPP_composite   "CompositePattern/Composite.cpp" )
add_executable (DesignPatternCPP_commpositeExample   "CompositePatternExample/CompositePatternExample.cpp" )
add_executable (DesignPatternCPP_singleton   "SingletonPattern/Singleton.cpp" )
add_executable (DesignPatternCPP_singletonThreadSafe   "SingeltonPatternThreadSafe/Singleton_ThreadSafe.cpp" )
add_executable (DesignPatternCPP_observer  "ObserverPattern/ObserverPattern.cpp" )
add_executable (DesignPatternCPP_observerExample  "ObserverPatternExample/RoomsAndSensors.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DesignPatternCPP PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
