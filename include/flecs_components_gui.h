#ifndef FLECS_COMPONENTS_GUI_H
#define FLECS_COMPONENTS_GUI_H

/* This generated file contains includes for project dependencies */
#include "flecs-components-gui/bake_config.h"

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef FLECS_COMPONENTS_GUI_IMPL
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

/* Canvas */

FLECS_COMPONENTS_GUI_API
ECS_STRUCT(EcsCanvas, {
    char *title;
    int32_t width;
    int32_t height;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
    ecs_entity_t camera;
    ecs_entity_t directional_light;
    EcsRgb background_color;
    EcsRgb ambient_light;
    EcsRgb ambient_light_ground;
    float ambient_light_ground_falloff;
    float ambient_light_ground_offset;
    float ambient_light_ground_intensity;
    float fog_density;
    float shadow_far;
});

/* Text & fonts */

FLECS_COMPONENTS_GUI_API
ECS_STRUCT(EcsText, {
    char *value;
});

FLECS_COMPONENTS_GUI_API
ECS_STRUCT(EcsFontSize, {
    int32_t value;
});

FLECS_COMPONENTS_GUI_API
ECS_ENUM(EcsFontStyle, {
    EcsFontStyleRegular,
    EcsFontStyleItalic,
    EcsFontStyleBold
});

/* Alignment */

FLECS_COMPONENTS_GUI_API
ECS_BITMASK(EcsAlign, {
    EcsAlignLeft    = 1,
    EcsAlignCenter  = 2,
    EcsAlignRight   = 4,
    EcsAlignTop     = 8,
    EcsAlignMiddle  = 16,
    EcsAlignBottom  = 32
});

FLECS_COMPONENTS_GUI_API
ECS_STRUCT(EcsPadding, {
    float value;
});


#ifdef __cplusplus
extern "C" {
#endif

FLECS_COMPONENTS_GUI_API
void FlecsComponentsGuiImport(
    ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs {
namespace components {

class gui {
public:
    using Align = EcsAlign;

    struct Canvas : EcsCanvas {
        Canvas() {
            this->title = nullptr;

            this->width = 0;
            this->height = 0;

            this->left = 0;
            this->right = 0;
            this->top = 0;
            this->bottom = 0;

            this->ambient_light.r = 1.0;
            this->ambient_light.g = 1.0;
            this->ambient_light.b = 1.0;

            this->background_color.r = 0.0;
            this->background_color.g = 0.0;
            this->background_color.b = 0.0;

            this->camera = 0;
            this->directional_light = 0;
        }
    };

    gui(flecs::world& ecs) {
        // Load module contents
        FlecsComponentsGuiImport(ecs);

        // Bind C++ types with module contents
        ecs.module<flecs::components::gui>();
        ecs.component<Canvas>();
    }
};

}
}

#endif
#endif

#endif
