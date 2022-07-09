cc_module(
   name = "A",
   src = "helloworld.cpp", # a.cc exports the module A
   impl_srcs = [
   ],
   deps = [
   ],
)


cc_module_binary(
   name = "helloworld",
   srcs = ["main.cc"],  # main.cc can import A
   deps = [":A"],       # we can depend on modules
)
