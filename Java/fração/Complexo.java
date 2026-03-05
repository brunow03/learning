class Complexo{

	private double re, img;

	public Complexo (double re, double img){
		this.re = re;
		this.img = img; 
	}

	public Complexo soma(Complexo z){
		Complexo w;
		w = new Complexo(re + z.re, img + z.img);
		return w;
	}

	public Complexo multiplicacao(Complexo z){
		Complexo w;
		w = new Complexo(re*z.re - img*z.img, re*z.img + z.re*img);
		return w;
	}

	public Complexo conjugado(){
		Complexo w;
		w = new Complexo(re, -img);
		return w;
	}

	public Complexo divisao(Complexo z){
		Complexo w;
		w = new Complexo((re*z.re + img*z.img) / (z.re*z.re + z.img*z.img), (img*z.re - re*z.img) / (z.re*z.re + z.img*z.img));
		return w;
	}

	public double modulo(){
		return (re*re + img*img);
	}

	public double argumento(){
		return Math.atan(img/re);
	}

	public void mostra_retangular(){
		System.out.println(re + " + " + img + "i");
	}

	public void mostra_polar(){
		System.out.println(this.modulo() + "*" + "(cos (" + this.argumento() + ") + i*sin (" + this.argumento() + ")");
	}

	public double retorna_real(){
		return re;
	}

	public double retorna_img(){
		return img;
	}

	public void altera_real(double a){
		re = a;
	}

	public void altera_img(double a){
		img = a;
	}
}