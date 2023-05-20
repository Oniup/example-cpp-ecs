#include "../ecs.hpp"

struct TransformComponent {
    float position[3] = {};
    float scale[3] = {};
    float rotation[4] = {};

    TransformComponent(float x_pos, float y_pos, float z_pos) {
        position[0] = x_pos;
        position[1] = y_pos;
        position[2] = z_pos;
    }
};

struct MeshRendererComponent {
    std::string path;
};

int main(int argc, char** argv) {
    ecs::Registry registry = ecs::Registry();

    for (std::size_t i = 0; i < 5; i++) {
        ecs::Entity entity = registry.create_entity();
        registry.create_component<TransformComponent>(entity, i, i + 1, i + 2);
    }

    auto view = ecs::View<TransformComponent>(&registry);
    for (ecs::Entity entity : view) {
        if (view.has_required(entity)) {
            // auto [transform, mesh_renderer] = view.get();
            TransformComponent* transform = view.get<TransformComponent>();

            std::cout << entity << "\n";
        } else {
            std::cout << "failed\n";
        }
    }

    return 0;
}
