from conan import ConanFile


class Example(ConanFile):
    name = "Example"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"
    requires = ["boost/1.71.0",
                "nlohmann_json/3.11.2",
                "openssl/1.1.1q",
                "websocketpp/0.8.2"]
