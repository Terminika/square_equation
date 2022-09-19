#ifndef func_h
#define func_h

/// @brief checks is less than definit small number
/// @param a first ratio in quadric equation
/// @return 0 if it is true, esle - a
int is_zero(float a);

/// @brief calculates discriminant of quadric equation 
/// @param a first ratio
/// @param b second ratio
/// @param c third ratio
/// @return calculated discriminant, one number
float discriminant (float a, float b, float c);

/// @brief solves a quadric equation using function discriminant, roots will be saved in variables x1 and x2 which was given with pointers
/// @param a first ratio
/// @param b second ratio
/// @param c third ratio
/// @param x1 first root
/// @param x2 second root
/// @return number of roots, 0 if there is np solution, 2 as usual
int quadratic_eq (float a, float b, float c, float *x1, float *x2);

/// @brief solves usual linear equation and degenerate cases, root will be saved in x1 which was given with pointer
/// @param b second ratio of quadric equation
/// @param c third ratio
/// @param x1 first root
/// @return number of roots, 0 if there is no solutions, 1 as usual and 3 if there is an infinity of solutions
int linear_eq (float b, float c, float *x1);

/// @brief prints the answer
/// @param root_num number of roots
/// @param  x1 first root if it exists
/// @param  x2 second root if it exists 
/// @return 0
int output (int root_num, float x1, float x2);

#endif