#include <stdio.h>
unsigned int l, h, v, s, maxs, i;

int main() {
	while (scanf("%u%u", &l, &h), l+h) {
	    if (l > h) l^=h^=l^=h;
	    printf("Between %u and %u, ", l, h);
	    for (maxs=0; l<=h; l++) {
	        i = l, s = 0;
	        do {
	            s++;
	            if (i&1) i = i*3+1;
	            else i /= 2;
	        } while (i != 1);
	        if (s > maxs)
	            maxs = s, v = l;
	    }
	    printf("%u generates the longest sequence of %u values.\n", v, maxs);
	}
}
