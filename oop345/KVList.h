//KVList.h
#pragma once

template<typename K, typename V, int N>
class KVList{

	K k[N];
	V v[N];

	//std::pair<K,V> table[N]
	//same thing
	//
	size_t count;

	public:

		KVList() 
		: count(0)
		{}

		size_t size() const {return count;}

		const K& key(int i) const {
		
			if (i >= 0 && i < count){
				//return table[i].first;
				return v[i];
			}
		}

		const K& value(int i) const {
		
			if(i >= 0 && i < count){
				//return table[i].second;
				return v[i];
			}
		}

		KVLIST& add(const K& kk, const V& vv) {
		
			if(count < N){
				k[count] = kk;
				v[count] = vv;
				//table[count] = std::make_pair<kk,vv>;
				count++;
			}
		}

		int find(const K& k) const {
		
			for(size_t i = 0; i < count; i++){
				
				if(k[i] == kk) return i;
				//if(table[i].first == kk) return i;
			}

			return 0;
		}

		KVList& replace(int i, const K& kk, const V& vv){
			

			if(i >=0 && i < count){
				//table[i] = std::make_pair(kk,vv)l
		
				k[i] = kk;
				v[i] = vv;
			}
		}



};

