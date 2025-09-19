package listas;

class No { // sem especificador de acesso na classe
	private char info;
	private No prox;

	No(char i, No p) // construtor
	{
		info = i;
		prox = p;
	}

	char retorna_info()
	{
		return info;
	}

	void altera_info(char i)
	{
		info = i;
	}

	void altera_prox(No p)
	{
		prox = p;
	}

	No retorna_prox()
	{
		return prox;
	}
}

public class Lista{

	private No cabeca; // inicio da lista
	private int elementos; //numeros de nos da lista

	public Lista() // construtor
	{
		cabeca = null;
		elementos = 0;
	}

	public void insere(char a)
	{
		elementos++;
		No temp;
		if(cabeca == null) cabeca = new No(a, null);
		else {
			temp = new No(a, null);
			temp.altera_prox(cabeca);
			cabeca = temp;
		}
	}

	public char remove()
	{
		No removido;
		if (cabeca == null) return '0'; //elementos == 0
		else {
			elementos--;
			removido = cabeca;
			cabeca = cabeca.retorna_prox();
			return removido.retorna_info();
		}
	}

	public int retorna_elementos()
	{
		return elementos;
	}

	public void mostra() // shouldn't be debugging feature
	{
		No temp = cabeca;
		while (temp != null){
			System.out.println( "[" + temp.retorna_info() + "]-" );
			temp = temp.retorna_prox();
		}
		System.out.println("null");
		System.out.println();
	}
}