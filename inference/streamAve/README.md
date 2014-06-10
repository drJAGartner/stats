##Inference directory contains data for reading in and analyzing data

###Stream Ave
Calculates an average & variance itteratively via the method proposed by knuth.  
This method out performs the direct calculation method when the number of entries is
extremely large.

###Stream Stat
Calculates average, variance, covariance & correlation for 2 sets of data.
In this case, averages & variance are computed via the direct technique:
> s^2 = (sum x^2 - (sum x)^2/N)/(N-1)