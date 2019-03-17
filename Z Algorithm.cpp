#include <bits/stdc++.h>

using namespace std;

int main(){
   string pat, text;
   cin >> pat >> text;

   string conc = pat + "$" + text;

   int z[conc.length()];
   z[0] = 0;
   int l, r;
   l = 0; r = 0;

   for (int i = 1; i < conc.length(); i++){
	   if(i > r){
		   l = r = i;
		   while (r < conc.length() && conc[r] == conc[r-l]){
			   r++;
		   }
		   z[i] = r-l;
		   r-- ;
	   }

	   else{
		   int k = i-l;
		   if(z[k] < r-l+1){
			   z[i] = z[k];
		   }

		   else{
			   l = k;
			   while (r < conc.length() && conc[r] == conc[r-l]){
				   r++;
			   }
			   z[i] = r-l;
			   r--;
		   }
	   }
   }

   for (int i = 0; i < conc.length(); i++){
	   if (z[i] == pat.length()) cout << i-pat.length() << " ";
   }
}
