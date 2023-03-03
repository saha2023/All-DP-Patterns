class Solution {
public:
	int total(int i,vector<int>& v, int a, int b){
		if(i==v.size()){
			if(a==b){
				return 0;
			}
		    return -1e9;
		}

		int x = total(i+1,v,a,b);
		int y = v[i] + total(i+1,v,a+v[i],b);
		int z = total(i+1,v,a,b+v[i]);

		return max({x,y,z});
	}
	int tallestBillboard(vector<int>& rods) {
		return total(0,rods,0,0);
	}
};


//space iptimisation
class Solution {
public:
	int total(int i,vector<int>& v, int diff){
		if(i==v.size()){
			if(diff == 0){
				return 0;
			}
		    return -1e9;
		}

		int x = total(i+1,v,diff);
		int y = v[i] + total(i+1,v,diff+v[i]);
		int z = total(i+1,v,a,diff);

		return max({x,y,z});
	}
	int tallestBillboard(vector<int>& rods) {
		return total(0,rods,0,0);
	}
};