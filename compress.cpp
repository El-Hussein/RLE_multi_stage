#include <bits/stdc++.h>
using namespace std;
string in, s, c_2, c_3, d_2, d_3;
short c, out;
int _00, _0, _2, _1, ind, cnt, res, _3, _4, _m, _11, nb = 7;

// return ascii of the char
int getInt(char c){
	int x = c;
	return x;}

// take char and output the binary opposite to it
void binStr(char x, int i=0){
	if(i==8)return;
	binStr(x, i+1);
	cout << ((x&(1<<i))?1:0);}

// take integer and output the binary opposite to it
void binInt(int x, int i=1){
	if(i==8)return;
	binInt(x/2, i+1);
	cout << x%2;}

// return integer value opposite to the bniary string
int revBin(string s,int i = 7){
	if(i==-1)return 0;
	return ((s[s.size()- i - 1]-'0')*pow(2,i)) + revBin(s, i-1);}

// prepare for the text gets the number of contiguous zeros and number of zeros and ones 
void count(){
	freopen("pre_stage_1.txt", "r", stdin);
	freopen("count_1.txt", "w", stdout);
	while(getline(cin, in)){
		for(int i=0;i<in.size();++i){
			if(in[i]=='0')_00++;
			else{
				_11++;
				_1+=(_00==1)?1:0;
				_2+=(_00==2)?1:0;
				_3+=(_00==3)?1:0;
				_4+=(_00==4)?1:0;
				_m+=_00;
				_00 = 0;
			}
		}
	}
	cout << "number of ones is :" << _11 << endl;
	cout << "number of zeros is :" << _m << endl;
	cout << "number of 1 zeros is :" << _1 << endl;
	cout << "number of 2 zeros is :" << _2 << endl;
	cout << "number of 3 zeros is :" << _3 << endl;
	cout << "number of 4 zeros is :" << _4 << endl;
	cout << "number of more than or equal 5 zeros is :" << _m << endl;
}

// converts all the file from binary string to binary bits store in char
void convert_to_bits(){
	freopen("compress_3.txt", "r", stdin);
	freopen("compressed.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size(); i+=8)
		{	
			cout << (char)revBin(in.substr(i, 8));
		}
	}
}

// reverse all file from chars to opposite binary
void retrieve_from_bits(){
	freopen("compressed.txt", "r", stdin);
	freopen("decompressed.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size(); ++i)
		{	
			binInt(getInt(in[i]), 0);
		}
	}
}

// first stage of compress removing first 8th bit from all char 
// as it is always zero due to the nature of the text
void compressStart(){
	freopen("orig.txt", "r", stdin);
	freopen("compress_1.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size(); ++i)
		{	
			binInt(getInt(in[i]));
		}

	}
}

// second stage applying RLE with 2 bits
void compress_2(){
	freopen("compress_1.txt", "r", stdin);
	freopen("compress_2.txt", "w", stdout);
	while(getline(cin, in)){
		for(int i=0;i<in.size();++i){
			if(in[i]=='0')_0++;
			else{
				while(_0>=0){
					if(_0>=3){
						binInt(3, 6);
					}else{
						binInt(_0, 6);
					}
					_0-=3;
				}
				_0 = 0;
			}
		}
	}
}

// third stage applying RLE with 3 bits 
void compress_3(){
	freopen("compress_2.txt", "r", stdin);
	freopen("compress_3.txt", "w", stdout);
	while(getline(cin, in)){
		for(int i=0;i<in.size();++i){
			if(in[i]=='0')_0++;
			else{
				while(_0>=0){
					if(_0>=7){
						binInt(7, 5);
					}else{
						binInt(_0, 5);
					}
					_0-=7;
				}
				_0 = 0;
			}
		}
	}
}

// decompress stage 1 with RLE 3 bits
void decompress_3(){
	freopen("compress_3.txt", "r", stdin);
	freopen("decompress_2.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size()-3; ++i)
		{	
			cnt=0;
			while(in.substr(i, 3)=="111"&&i<in.size()-3){
				cnt+=revBin("111", 2);
				i+=3;
			}
			cnt+=revBin(in.substr(i,3), 2);
			i+=2;
			for (int j = 0; j < cnt; ++j)
			{
				cout << '0';
			}cout << '1';
		}
	}
}

// decompress stage 2 with RLE 2 bits
void decompress_2(){
	freopen("decompress_2.txt", "r", stdin);
	freopen("decompress_1.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size()-2; ++i)
		{	
			cnt=0;
			while(in.substr(i, 2)=="11"&&i<in.size()-2){
				cnt+=revBin("11", 1);
				i+=2;
			}
			cnt+=revBin(in.substr(i,2), 1);
			i+=1;
			for (int j = 0; j < cnt; ++j)
			{
				cout << '0';
			}cout << '1';
		}
	}
}

// retrieve the 8th bit and get the orignal text
void decompressFinal(){
	freopen("decompress_1.txt", "r", stdin);
	freopen("decompress.txt", "w", stdout);
	while(getline(cin, in)){
		for (int i = 0; i < in.size()-7; i+=7)
		{	
			cout << (char)revBin(in.substr(i, 7), 6);
		}
	}
}


int main(){
	///////////////////
	///////////////////
	/// COMPRESSION ///
	///////////////////
	///////////////////

	// compressStart();
	// compress_2();
	// compress_3();

	// convert_to_bits();

	////////////////////////////////

	///////////////////
	///////////////////
	// DECOMPRESSION //
	///////////////////
	///////////////////

	// retrieve_from_bits();

	// decompress_3();
	// decompress_2();
	// decompressFinal();

}