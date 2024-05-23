import java.io.DataInputStream;

class ReadString{

	public static void main(String[] args) {
		String linha = "";
		DataInputStream meuDataInputStrig;
		meuDataInputStrig = new DataInputStream(System.in);

		try {
			linha = meuDataInputStrig.readLine();
		}
		catch (Exception erro) {
			System.out.println("Erro de leitura.");
		}

		System.out.println(linha);
	}

	static int leInteiro()
	{
		String line;

		DataInputStream in = new DataInputStream(System.in);
		try {
			line = in.readLine();
			int i = Integer.valueOf(line).intValue();
			return i;
		}
		catch (Exception e) {
			return -1;
		}
	}
}