export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

export src_dir := src
export obj_dir := build

src_files = $(wildcard $(src_dir)/*.cpp)
obj_files = $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files))

all_obj_files = $(obj_files)

all: libxml

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@mkdir -p $(dir $@)
	$(cc) $(cpp_flags) -c $< -o $@

libxml: $(all_obj_files)
	$(cc) $(cpp_flags) -shared -o libxml.so $(all_obj_files)
	ar rcs libxml.a $(all_obj_files)

clean:
	rm -rf $(obj_dir) *.so *.a
