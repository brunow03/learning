class Fracao{

	private int num, den;

	private int mdc(int n, int d){
		if (n < 0) 
			n = -n;
		if (d < 0)
			d = -d;
		while (d != 0){
			int r = n % d;
			n = d;
			d = r;
		}
		return n;
	}

	public Fracao (int t, int m){
		num = t;
		den = m;
		this.simplifica();
	}

	public void simplifica(){
		int commd;
		commd = mdc(num,den);
		num = num / commd;
		den = den / commd;
		if (den < 0) {
			den = -den;
			num = -num;
		}
	}

	public Fracao soma(Fracao j){
		Fracao g;
		g = new Fracao((num*j.den) + (j.num*den), den*j.den);
		return g;
	}

	public Fracao multiplicacao(Fracao j){
		Fracao g;
		g = new Fracao(num*j.num, den*j.den);
		return g;
	}

	public boolean igual(Fracao t){
		return ((num*t.den) == (den*t.num));
	}

	public boolean diferente(Fracao t){
		return ((num*t.den) != (den*t.num));
	}

	public boolean maiorouigual(Fracao t){
		return ((num*t.den) >= (t.num*den));
	}
	
	public void mostra(){
		System.out.println("(" + num + "/" + den + ")");
	}

	public double convertedbl(){
		double dbl;
		dbl = ((double)num/(double)den);
		return dbl;
	}

	public int converteint(){
		int itng;
		itng = num/den;
		return itng;
	}

	public void altera_num(int nn){
		num = nn;
	}

	public void altera_den(int nd){
		den = nd;
	}

	public int retorna_num(){
		return num;
	}

	public int retorna_den(){
		return den;
	}
}