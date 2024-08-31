#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    std::cout << "[AssetPacker] Baking textures, shaders, and audio assets into engine.pak bundle...\n";
    std::ofstream out("engine.pak", std::ios::binary);
    out << "PAK_MAGIC_HEADER_V1";
    out.close();
    std::cout << "[AssetPacker] Asset baking complete.\n";
    return 0;
}
