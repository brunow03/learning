class X{

	int val;

	public void change(X values)
	{
		int a;
		a = val;
		val = values.val;
		values.val = a;
	}
}