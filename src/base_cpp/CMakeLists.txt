
file(GLOB XPN_BASE_CPP_HEADERS
        "*.hpp"
)

file(GLOB XPN_BASE_CPP_SOURCE
        "*.cpp"
)

add_library(xpn_base_cpp OBJECT ${XPN_BASE_CPP_SOURCE} ${XPN_BASE_CPP_HEADERS})
target_include_directories(xpn_base_cpp PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
)   