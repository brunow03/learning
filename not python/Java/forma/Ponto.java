class Ponto{
	public Ponto(float a, float b){
		super(a,b);
	}
	public float distancia(Ponto a){
		return Math.sqrt( (double) Math.pow(this.retorna_x() - a.retorna_x() + Math.pow(this.retorna_y() - a.retorna_y(), 2) );
	}
	public void mostra(){
		System.out.println("x: " + this.retorna_x() + ", y: " + this.retorna_y());
	}
}