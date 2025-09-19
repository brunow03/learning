class Matriz2DInt{
	private int linhas;
	private int colunas;
	private int tam;
	private int lc[];

	public Matriz2DInt(int l, int c){
		lc = new int[l*c];
		linhas = l;
		colunas = c;
		tam = linhas * colunas;
	}

	public int linear(int alin, int acol){
		int result;
		if ((0<alin) && (alin <= linhas) && (0 < acol) && (acol <= colunas)) {
			result = (alin-1)*colunas + acol;
		}
		else {
			result = -1;
		}
		return result;
	}

	public int col(int indlin){
		int result;
		if ((0 < indlin) && (indlin <= tam)) {
			result = (indlin % colunas);
			if (result == 0) {
				result = colunas;
			}
		}
		else {
			result = -1;
		}
		return result;
	}

	public int lin(int indlin){
		int result;
		if ((0 < indlin) && (indlin <= tam)) {
			result = (int)(((indlin - 1)/colunas) + 1);
		}
		else {
			result = -1;
		}
		return result;
	}

	public boolean trocaindlin(int i, int j){
		int aux;
		if ((0 < i) && (i <= tam) && (j <= tam)) {
			aux = lc[i-1];
			lc[i-1] = lc[j-1];
			lc[j-1] = aux;
			return true;
		}
		else {
			return false;
		}
	}

	public boolean atribuiindlin(int i, int v){
		if ((0 < i) && (i <= tam)) {
			lc[i-1] = v;
			return true;
		}
		else {
			return false;
		}
	}

	public int retornaindlin(int indlin){
		int result;
		if ((0 < indlin) && (indlin <= tam)) {
			result = lc[indlin-1];
		}
		else {
			result = -1;
		}
		return result;
	}

	public int getl(){
		return linhas;
	}

	public int getc(){
		return colunas;
	}

	public int gett(){
		return tam;
	}
}