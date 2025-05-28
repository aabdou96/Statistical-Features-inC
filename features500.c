/*
 * features500.c
 *
 *  Created on: Jan. 14, 2022
 *      Author: aabdo
 */


#include<stdio.h>
#include<math.h>

#define SR 100

int accel_x[SR], accel_y[SR],accel_z[SR];
int gyr_x[SR],gyr_y[SR],gyr_z[SR];
float *p; //used for rms example in main : p = get_rms();

int get_max(int array[]){
	int i, max, size;
	size = SR;
	max = array[0];
	for (i=0; i<size;i++){
		if(array[i]>max){
			max = array[i];
		}
	}
return max;}

int get_min(int array[]){
	int i, min, size;
	size = SR;
	min = array[0];
	for (i=0; i<size;i++){
		if(array[i]<min){
			min = array[i];
		}
	}
return min;}

float get_mean(int array[]){
		int i, size;
		float y, sum = 0, mean;
		size = SR;
		for(i =0;i<= size;++i){
			sum +=array[i];
		}
		mean = sum/size;
		return mean;
}

float get_std(float array[]){
	int i, size = SR;
	float sum =0, mean= 0, std =0;
	for(i =0;i<= size;++i){
				sum +=array[i];
			}
	mean = sum/size;
	for(i=0;i<size;++i){
		std +=pow(array[i]-mean,2);
	}
	std = sqrt(std/size);
	return std;
}

float get_skewness(float array[]){
	int i, size;
	float sum = 0;
	size =SR;
	for (i = 0; i < size; i++){
	        sum += (array[i] - get_mean(array)) *
	              (array[i] - get_mean(array)) *
	              (array[i] - get_mean(array));}
	    return sum / (size* get_std(array)*
	    				get_std(array)*
						get_std(array)*
						get_std(array));
}

float get_kurtosis(float array[]){
	  int i, size =SR;
	  float sum = 0;
	  float mean = 0;

	  // Calculate mean
	  for (i = 0; i < size; i++) {
	    sum += array[i];
	  }
	  mean = sum / size;

	  // Calculate sum((x-mean(x))^4) and sum((x-mean(x))^2)
	  float r = 0;
	  float q = 0;
	  for (i = 0; i < size; i++) {
	    r += pow(array[i] - mean,  4);
	    q += pow(array[i] - mean,  2);
	  }

	  float k = size*r / pow(q, 2);
	  return k;
}

float *get_rms(int array1[], int array2[], int array3[]){
	int i=0, size;
	size = SR;

	float pow_array[size];
	static float rms_array[size];

	for(i=0;i<size;i++){
		pow_array[i] =0;
		rms_array[i] =0;
	}
	for(i=0;i<size;i++){
	pow_array[i] = pow(array1[i], 2) + pow(array2[i], 2) + pow(array3[i], 2);
	rms_array[i] = sqrt(pow_array[i]);
	}
	return rms_array;
}

int get_ZC(int array[]){
       int ZC_counter=0;
       int size= SR;

       for (int i=0; i<size-1; i++){
               if((array[i]>=0 && array[i+1]<0) || (array[i]<0 && array[i+1]>=0)){
                   ZC_counter++;
               }
       }

       return ZC_counter;
   }

int get_SE(int array[]){
	int size= SR;
	int SE = 0, i;
	for(i=0;i<size;i++){
		SE += pow(array[i],2);
	}
	return SE;
}

int get_p2p(int array[]){
		int size = SR; int i;
		int diff; int max; int min;

		max = array[0];
			for (i=0; i<size;i++){
				if(array[i]>max){
					max = array[i];
				}
			}
		min = array[0];
			for (i=0; i<size;i++){
				if(array[i]<min){
					min = array[i];
				}
			}
		diff = max-min;
		return diff;
}

int get_pk2rms(int array[]){
	int size = SR; int i =0;
	int pk2rms; int abs_max;

	abs_max = abs(array[0]);
				for (i=0; i<size;i++){
					if(abs(array[i])>abs_max){
						abs_max = abs(array[i]);
					}
				}

	float pow_value = 0;
	static float rms;
		for(i=0;i<size;i++){
				pow_value += pow(array[i], 2);
				}
	rms = sqrt(pow_value/size);
	pk2rms = abs_max/rms;
	return pk2rms;
}

int get_rrsq(int array[]){
	int size = SR; int i =0;
	int S = 0; int rssq;
		for(i=0;i<size;i++){
			S += pow(array[i],2);
		}
	rssq = sqrt(S);

	return rssq;
}
