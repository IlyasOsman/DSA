bool isPrime(int n)
{
	// Write your code here.
	int count { 1 };
	for(int i { 1 }; i*i < n; i++)
	{
		if(n % i == 0)
			count++;
	}

	return count == 2;
}
