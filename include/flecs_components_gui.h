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

typedef struct EcsCanvas {
    int32_t width;
    int32_t height;
    ecs_rgb_t background_color;
    ecs_entity_t camera;
    ecs_rgb_t ambient_light;
    ecs_entity_t directional_light;
} EcsCanvas;

typedef struct FlecsComponentsGui {
    ECS_DECLARE_COMPONENT(EcsWindow);
    ECS_DECLARE_COMPONENT(EcsCanvas);
} FlecsComponentsGui;

void FlecsComponentsGuiImport(
    ecs_world_t *world);

#define FlecsComponentsGuiImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsWindow);\
    ECS_IMPORT_COMPONENT(handles, EcsCanvas);

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

    struct Canvas : EcsCanvas {
        Canvas() {
            this->ambient_light.r = 1.0;
            this->ambient_light.g = 1.0;
            this->ambient_light.b = 1.0;

            this->background_color.r = 0.0;
            this->background_color.g = 0.0;
            this->background_color.b = 0.0;
        }
    };

    gui(flecs::world& ecs) {
        FlecsComponentsGuiImport(ecs.c_ptr());

        ecs.module<flecs::components::gui>();

        ecs.pod_component<Window>("flecs::components::gui::Window");
        ecs.pod_component<Canvas>("flecs::components::gui::Canvas");
    }
};

}
}

#endif

#endif
