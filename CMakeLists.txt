cmake_minimum_required (VERSION 2.6)
project (Snake)

add_subdirectory(../oxygine/oxygine-framework oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")

add_executable(Snake src/main.cpp src/Objects/Direction.h
		src/init.cpp src/Snake/SnakeBody.cpp src/Snake/SnakeNervousSystem.cpp
		src/init.h src/Snake/SnakeNervousSystem.h src/Snake/SnakeBody.h
		src/Objects/Position.h src/Objects/WillMove.h src/Objects/Size.h
		src/Objects/StepSize.h src/Food/IFood.h src/Food/SmallFood.cpp src/Food/SmallFood.h
		src/System/Game.cpp src/System/Game.h src/System/Menu.cpp src/System/Menu.h
		src/System/MenuItem.cpp src/System/MenuItem.h src/System/Button/ButtonBlack.cpp
		src/System/Button/ButtonBlack.h src/System/Button/AbstractButton.h
		src/System/Text/AbstractText.h src/System/Text/TextMainButton.cpp
		src/System/Text/TextMainButton.h src/Objects/ButtonTypes.h src/Objects/TextTypes.h src/Global/Percentage.cpp src/Global/Percentage.h)
target_link_libraries(Snake ${OXYGINE_CORE_LIBS})



if (WIN32) #disable console mode for VC++
	set_target_properties(Snake PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)



if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648")
	em_link_pre_js(Snake  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)