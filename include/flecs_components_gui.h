#ifndef FLECS_COMPONENTS_GUI_H
#define FLECS_COMPONENTS_GUI_H

/* This generated file contains includes for project dependencies */
#include "flecs-components-gui/bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(EcsWindow, {
    char *title;
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
});

ECS_STRUCT(EcsCanvas, {
    int32_t width;
    int32_t height;
    ecs_rgb_t background_color;
    ecs_entity_t camera;
});

typedef struct EcsCamera {
    vec3 position;
    vec3 lookat;
    vec3 up;
    float fov;
} EcsCamera;

typedef struct FlecsComponentsGui {
    ECS_DECLARE_COMPONENT(EcsWindow);
    ECS_DECLARE_COMPONENT(EcsCanvas);
    ECS_DECLARE_COMPONENT(EcsCamera);
} FlecsComponentsGui;

void FlecsComponentsGuiImport(
    ecs_world_t *world);

#define FlecsComponentsGuiImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsWindow);\
    ECS_IMPORT_COMPONENT(handles, EcsCanvas);\
    ECS_IMPORT_COMPONENT(handles, EcsCamera);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace flecs {
namespace components {

class gui : FlecsComponentsGui {
public:
    struct Window : EcsWindow {
        Window() {
            this->title = nullptr;
            this->x = 0;
            this->y = 0;
            this->width = 0;
            this->height = 0;
        }
    };

    using Canvas = EcsCanvas;

    struct Camera : EcsCamera {
        Camera() {
            this->set_position(0, 0, 0);
            this->set_lookat(0, 1, 1);
            this->set_up(0, -1, 0);
            this->set_fov(30);
        }

        void set_position(float x, float y, float z) {
            this->position[0] = x;
            this->position[1] = y;
            this->position[2] = z;
        }

        void set_lookat(float x, float y, float z) {
            this->lookat[0] = x;
            this->lookat[1] = y;
            this->lookat[2] = z;
        }

        void set_up(float x, float y, float z) {
            this->up[0] = x;
            this->up[1] = y;
            this->up[2] = z;
        }

        void set_fov(float value) {
            this->fov = value;
        }
    };

    gui(flecs::world& ecs) {
        FlecsComponentsGuiImport(ecs.c_ptr());

        ecs.module<flecs::components::gui>();

        ecs.pod_component<Window>("flecs::components::gui::Window");
        ecs.pod_component<Canvas>("flecs::components::gui::Canvas");
        ecs.pod_component<Camera>("flecs::components::gui::Camera");
    }
};

}
}

#endif

#endif
