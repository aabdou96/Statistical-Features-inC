/*
 * features500.h
 *
 *  Created on: Jan. 17, 2022
 *      Author: aabdo
 */

#ifndef FEATURES500_H_
#define FEATURES500_H_

int get_max(int array[]); //max
int get_min(int array[]); //min
float get_mean(int array[]); //mean of signal
float get_std(float array[]); // standard deviation
float get_skewness(float array[]); //skewness of the signal
float get_kurtosis(float array[]); // kurtosis of the signal
float *get_rms(int array1[], int array2[], int array3[]); //root-mean squared of (x,y,z)
int get_ZC(int array[]); // Zero-crossing rate
int get_SE(int array[]); // Signal energy
int get_p2p(int array[]); // Peak2Peak of the signal
int get_pk2rms(int array[]); // Peak2RMS ratio of the signal
int get_rrsq(int array[]); // Root-sum-of-squares of the signal



#endif /* FEATURES500_H_ */
