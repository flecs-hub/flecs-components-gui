#include <flecs_components_gui.h>

void FlecsComponentsGuiImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsGui);

    ecs_set_name_prefix(world, "Ecs");

    ECS_IMPORT(world, FlecsMeta);
    ECS_IMPORT(world, FlecsComponentsGraphics);

    ECS_META(world, EcsWindow);
    ECS_META(world, EcsCanvas);
    ECS_COMPONENT(world, EcsCamera);

    ECS_EXPORT_COMPONENT(EcsWindow);
    ECS_EXPORT_COMPONENT(EcsCanvas);
    ECS_EXPORT_COMPONENT(EcsCamera);
}