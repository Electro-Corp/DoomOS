/*
*I_GetTime
*/
#ifndef TIME_H
#define TIME_H
struct timeval {
	int tv_sec;
	int tv_usec;
};
struct timezone {

};

int gettimeofday(struct timeval* restrict tv, struct timezone* restrict tz) {
	return 0;
}
#endif