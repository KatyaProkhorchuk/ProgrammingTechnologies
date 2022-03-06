import sys
file = open(sys.argv[1]+"/index.h","w")
file.write("const int A = 1;")
file.close()