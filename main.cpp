#include "src/rtweekend.h"
#include "src/color.h"
#include "src/hittable.h"
#include "src/sphere.h"
#include "src/hittable_list.h"
#include "src/camera.h"

#include <iostream>

//double hit_sphere(const point3 &center, double radius, const ray &ray) {
//    vec3 oc = ray.orign() - center;
//    auto a = ray.direction().length_squared();
//    auto half_b = dot(oc, ray.direction());
//    auto c = oc.length_squared() - radius * radius;
//    auto discriminant = half_b * half_b - a * c;
//
//    if (discriminant < 0) return -1.0;
//    else return (-half_b - sqrt(discriminant)) / (2.0 * a);
//
//}

color ray_color(const ray &ray, const hittable& world) {
    hit_record record;
    if (world.hit(ray, 0, infinity, record))
        return 0.5 * (record.normal + color(1, 1, 1));

    vec3 unit_direction = unit_vector(ray.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

    return (1.0 - t)* color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;

    //World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera
    camera cam;

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int k = 0; k < samples_per_pixel; ++k) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height -1);
                ray ray = cam.get_ray(u, v);
                pixel_color += ray_color(ray, world);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone. \n";
}
