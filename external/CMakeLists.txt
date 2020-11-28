#外部第三方库
set(DESCRIPTION "third libraries")
add_subdirectory(boost)
add_subdirectory(boost_outcome)

#add_definitions(-std=c++11)  # 指定采用c++11进行编译（spdlog需要c++11）
# git submodule add https://github.com/mysql/mysql-connector-cpp.git
# cd mysql-connector-cpp

add_subdirectory(mysql-connector-cpp)