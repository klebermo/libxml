export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

export src_dir := src
export obj_dir := build

src_files = $(wildcard $(src_dir)/*.cpp)
obj_files = $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files))

schema_dir := $(src_dir)/schema
schema_obj_files := $(patsubst %.cpp, %.o, $(wildcard $(schema_dir)/*.cpp))

schema_simple_dir := $(src_dir)/schema/simple
schema_simple_obj_files := $(patsubst %.cpp, %.o, $(wildcard $(schema_simple_dir)/*.cpp))

query_dir := $(src_dir)/query
query_obj_files := $(patsubst %.cpp, %.o, $(wildcard $(query_dir)/*.cpp))

all_obj_files = $(obj_files) $(schema_obj_files) $(schema_simple_obj_files) $(query_obj_files)

all: libxml

$(schema_obj_files):
	$(MAKE) -C $(schema_dir) cpp_flags="$(cpp_flags)"

$(schema_simple_obj_files):
	$(MAKE) -C $(schema_simple_dir) cpp_flags="$(cpp_flags)"

$(query_obj_files):
	$(MAKE) -C $(query_dir) cpp_flags="$(cpp_flags)"

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@mkdir -p $(dir $@)
	$(cc) $(cpp_flags) -c $< -o $@

libxml: $(all_obj_files)
	$(cc) $(cpp_flags) -shared -o libxml.so $(all_obj_files)
	ar rcs libxml.a $(all_obj_files)

clean:
	rm -rf $(obj_dir) *.so *.a
	$(MAKE) -C $(schema_dir) clean
	$(MAKE) -C $(schema_simple_dir) clean
	$(MAKE) -C $(query_dir) clean
