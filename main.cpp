#include <iostream>
#include "src/color.h"
#include "src/ray.h"

double hit_sphere(const point3 &center, double radius, const ray &ray) {
    vec3 oc = ray.orign() - center;
    auto a = dot(ray.direction(), ray.direction());
    auto b = 2.0 * dot(oc, ray.direction());
    auto c = dot(oc, oc) - radius * radius;

    auto discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return -1.0;
    else return (-b - sqrt(discriminant)) / (2.0 * a);

}

color ray_color(const ray &ray) {
    auto t = hit_sphere(point3(0, 0, -1), 0.5, ray);
    if (t > 0.0) {
        vec3 N = unit_vector(ray.at(t) - vec3(0, 0, -1));
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    vec3 unit_direction = unit_vector(ray.direction());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Scene
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_lenght = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_lenght);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            ray ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(ray);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone. \n";
}
