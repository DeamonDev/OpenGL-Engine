TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGL -lpthread -lX11 -lXxf86vm -lXrandr -lXi -lGLEW -lm

SOURCES += main.cpp \
    game_manager.cpp \
    render_system.cpp \
    shader_loader.cpp \
    shader_manager.cpp \
    vertex.cpp \
    entity.cpp \
    line.cpp \
    entity_manager.cpp \
    triangle.cpp \
    camera.cpp \
    camera_manager.cpp \
    transform.cpp \
    cube.cpp \
    texture.cpp

HEADERS += \
    game_manager.h \
    render_system.h \
    shader_loader.h \
    shader_manager.h \
    vertex.h \
    entity.h \
    line.h \
    entity_manager.h \
    triangle.h \
    camera.h \
    camera_manager.h \
    transform.h \
    cube.h \
    texture.h

OTHER_FILES += \
    Shaders/basic_shader.frag \
    Shaders/basic_shader.vert

