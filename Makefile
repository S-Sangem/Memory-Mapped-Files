all: alloc prov-rev

alloc: alloc.cpp
		gcc -o alloc alloc.cpp -lstdc++

prov-rev: prov-rev.cpp
				gcc -o prov-rev prov-rev.cpp -lstdc++
