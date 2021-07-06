package Manipolazione;

import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Random;
import java.util.Scanner;


public class DB {
	
	private static final String ins = "insert into ";
	private Connection conn;
	private Statement stmt;
	private Random r;
	private ArrayList<String> nomi = new ArrayList<>();
	private ArrayList<String> cognomi= new ArrayList<>();
	private ArrayList<String> nazioni= new ArrayList<>();
	
	
	public DB(String username, String password, String dbName) throws SQLException {
		r = new Random();
		try {
			fileToArray("Nomi.txt", nomi);
			fileToArray("Cognomi.txt", cognomi);
			fileToArray("Nazioni.txt", nazioni);
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/" + dbName +"?useUnicode=true&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC", username, password);
			stmt = conn.createStatement();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void close() throws SQLException {
		if(conn != null)
			conn.close();
		if(stmt != null)
			stmt.close();
	}

	public void deleteTable(String nome) {
		String del = "delete from ";
		try {
			stmt.executeUpdate(del + nome);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	
	public void delete(String nome, String whereCause) {
		String del = "delete from ";
		try {
			if(nome.compareTo("Container") == 0) {
				ResultSet risultato = stmt.executeQuery("select nave from Container "+ " WHERE " + whereCause);
				ArrayList<Integer> imo = new ArrayList<>();
				while(risultato.next()) {
					imo.add( Integer.parseInt(risultato.getString("nave")) );
				}
				for(int i=0; i<imo.size(); i++)
					stmt.execute("update nave set effContainer = effContainer-1 where imo = " + imo.get(i) + ";");
			}else {
				stmt.executeUpdate(del + nome + " WHERE " + whereCause);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public boolean insertCliente(String cf, String nome, String cognome, String dataNascita) {
		try {
			stmt.execute(ins + "Cliente(CF,nome, cognome, dataNascita) value (\"" +cf+ "\", \"" +nome+ "\", \"" +cognome+ "\", \"" +dataNascita+ "\");" );
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertBroker(String cf, String nome, String cognome, String dataNascita, String matricola) {
		try {
			stmt.execute(ins + "Broker(CF,nome, cognome, dataNascita, matricola) value (\"" +cf+ "\", \"" +nome+ "\", \"" +cognome+ "\", \"" +dataNascita+ "\", \"" +matricola+ "\");" );
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertAmministratori(String dataInizio, String dataFine, String cf, int imo) {
		try {
			stmt.execute(ins + "Amministratore value(\"" +dataInizio+ "\", \"" +dataFine+ "\", \"" +cf+ "\", " +imo+ ");");
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertNavi(int imo, int effC, int maxC, double lunghezza, double larghezza, double pescaggio, int anno) {
		try {
			stmt.execute(ins + "Nave value(" +imo+ ", " +effC+ ", " +maxC+ ", " +lunghezza+ ", " +larghezza+ ", " +pescaggio+ ", " +anno+ ");");
				return true;
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertViaggio(String dataInizio, int imo, String locodeP, String locodeA) {
		try {
			stmt.execute(ins+ "Viaggio value(\"" +dataInizio+ "\", " +imo+ ", \"" + locodeP + "\", \"" + locodeA + "\");");
			return true;
		}catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertPorto(String locode, String nome) {
		try {
			stmt.execute(ins+ "Porto value(\"" +locode+ "\", \"" +nome+ "\");");
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertProprietario(int bic, String cf) {
		try {
			stmt.execute(ins+ "Proprietario value(" +bic+ ", \"" +cf+ "\");");
			return true;
		}catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertContainer(int bic, String categoria, int imo, String locodeP, String dataP, String locodeA) {
		try {
			ResultSet risultato = stmt.executeQuery("select effContainer, maxContainer from nave where imo = " + imo + ";");
			int eff = 0;
			int max = 0;
			while(risultato.next()) {
				eff = Integer.parseInt(risultato.getString("effContainer"));
				max = Integer.parseInt(risultato.getString("maxContainer"));
			}
			if(eff < max) {
				stmt.execute(ins+ "Container value(" +bic+ ", \"" +categoria+ "\", " +imo+ ", \"" +locodeP+ "\", \"" +dataP+ "\", \"" +locodeA+ "\");");
				stmt.execute("update nave set effContainer = effContainer+1 where imo = " + imo + ";");
				return true;
			}else
				return false;
		}catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertContainer(int bic, String categoria, String locodeP, String dataP, String locodeA) {
		try {
			stmt.execute(ins+ "Container(bic, categoria, portoPartenza, dataPartenza, portoArrivo) value(" +bic+ ", \"" +categoria+ "\", " + "\"" +locodeP+ "\", \"" +dataP+ "\", \"" +locodeA+ "\");");
			return true;
		}catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	public boolean insertScalo(String locode, String data, int imo) {
		try {
			stmt.execute(ins+ "Scalo value(\"" +locode+ "\", \"" +data+ "\", " +imo+ ");");
			return true;
		}catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}
	
	//Derivati
	
	public void deleteAllTable() {
		deleteTable("Cliente");
		deleteTable("Broker");
		deleteTable("Amministratore");
		deleteTable("Nave");
		deleteTable("Viaggio");
		deleteTable("Porto");
		deleteTable("Proprietario");
		deleteTable("Container");
		deleteTable("Scalo");
		System.out.println("Eliminazione Completata!");
	}

	public void generaClienti(int n) {
		System.out.println("Generazione Clienti");
		int i = 0;
		while(i < n){
			String cf = nomi.get( r.nextInt(nomi.size())).charAt(0) + "" + (i+100) + "" + nomi.get( r.nextInt(nomi.size() )).charAt(0);
			String nom = nomi.get(r.nextInt(nomi.size()-1));
			String cgn = cognomi.get(r.nextInt(cognomi.size()-1));
			String dataNascita = (r.nextInt(100)+1900) + "-" + (r.nextInt(12)+1) + "-" + (r.nextInt(29));
			if(insertCliente(cf, nom, cgn, dataNascita))
				i++;
		}
	}

	public void generaBroker(int n) {
		System.out.println("Generazione Broker");
		int i = 0;
		while(i < n){
				String cf = nomi.get( r.nextInt(nomi.size())).charAt(0) + "" + (i+100) + "" + nomi.get( r.nextInt(nomi.size() )).charAt(0);
				String nom = nomi.get(r.nextInt(nomi.size()-1));
				String cgn = cognomi.get(r.nextInt(cognomi.size()-1));
				String dataNascita = (r.nextInt(100)+1900) + "-" + (r.nextInt(12)+1) + "-" + (r.nextInt(29));
				String matricola = String.valueOf(i);
				if(insertBroker(cf, nom, cgn, dataNascita, matricola))
					i++;
		}
	}

	
	public void generaAmministratori(int n) {
		System.out.println("Generazione Amministratori");
		Calendar oggi = new GregorianCalendar();
		ArrayList<String> listaImo = queryToArrayList("SELECT IMO FROM Nave", "IMO");
		ArrayList<String> listaBroker = queryToArrayList("SELECT CF FROM Broker WHERE matricola IS NOT NULL", "CF");
		int i = 0;

		while( i<listaImo.size()) {
			Calendar data1 = new GregorianCalendar((oggi.get(Calendar.YEAR) - 1), r.nextInt(12), r.nextInt(29) );
			Calendar data2 = (Calendar) data1.clone();
			data2.add(Calendar.MONTH, 1);
			data2.add(Calendar.DATE, r.nextInt(32));

			String dataInizio = data1.get(Calendar.YEAR) + "-" + (data1.get(Calendar.MONTH)+1) + "-" + data1.get(Calendar.DATE);
			String dataFine= data2.get(Calendar.YEAR) + "-" + (data2.get(Calendar.MONTH)+1) + "-" + data2.get(Calendar.DATE);
			String broker =  listaBroker.get(0);
			int nave = Integer.parseInt( listaImo.get( i ));

			if(insertAmministratori(dataInizio, dataFine, broker, nave))
				i++;
		}
		
		
		i = 0;

		while(i < n){
			Calendar data1 = new GregorianCalendar((oggi.get(Calendar.YEAR) - 1), r.nextInt(12), r.nextInt(29) );
			Calendar data2 = (Calendar) data1.clone();
			data2.add(Calendar.MONTH, 1);
			data2.add(Calendar.DATE, r.nextInt(32));

			String dataInizio = data1.get(Calendar.YEAR) + "-" + (data1.get(Calendar.MONTH)+1) + "-" + data1.get(Calendar.DATE);
			String dataFine= data2.get(Calendar.YEAR) + "-" + (data2.get(Calendar.MONTH)+1) + "-" + data2.get(Calendar.DATE);
			String broker =  listaBroker.get(r.nextInt(listaBroker.size()));
			int nave = Integer.parseInt( listaImo.get( r.nextInt( listaImo.size() ) ) );

			if(insertAmministratori(dataInizio, dataFine, broker, nave))
				i++;
		}
	}

	public void generaNavi(int n) {
		System.out.println("Generazione Navi");
		int i = 0;
		while(i < n){
			int imo = r.nextInt(1000)+ i*10000;
			int maxC = r.nextInt(101);
			double lunghezza = Math.floor((r.nextDouble()*10000)) / 100;
			double larghezza = Math.floor((r.nextDouble()*10000)) / 100;
			double pescaggio = Math.floor((r.nextDouble()*1000)) / 100 ;
			int anno = (r.nextInt(100) + 1920);

			if(insertNavi(imo, 0, maxC, lunghezza, larghezza, pescaggio, anno))
				i++;
		}
	}

	public void generaPorti(int n) {
		System.out.println("Generazione Porti");
		int i = 0;
		while(i < n){
			String lettere = generaLettere(3);
			String nazione = nazioni.get(r.nextInt(nazioni.size()))+ " " + lettere;
			String nome = lettere.charAt(0) + generaLettere(3).toLowerCase() + lettere.charAt(1) + generaLettere(3).toLowerCase() + lettere.charAt(2);

			if(insertPorto(nazione, nome))
				i++;
		}
	}

	public void generaScali(int n) {
		System.out.println("Generazione Scali");
		ArrayList<String> listaImo = queryToArrayList("SELECT nave, dataInizio FROM Viaggio", "nave");
		ArrayList<String> listaData = queryToArrayList("SELECT nave, dataInizio FROM Viaggio", "dataInizio");
		ArrayList<String> listaLocode = queryToArrayList("SELECT LOCODE FROM Porto", "LOCODE");
		int i = 0,y=r.nextInt(10)+1;
		i=0;
		
		while(i < n){
			if(y==0)
				y=r.nextInt(10)+1;
			int x = r.nextInt(listaImo.size());
			int nave = Integer.parseInt(listaImo.get(x));
			String data= listaData.get(x);
			
			while(y > 0) {
				String porto= listaLocode.get( r.nextInt( listaLocode.size() ) );	
				if(insertScalo(porto, data, nave))
					y--;
			}
			i++;
		}
	}
	
	
	public void generaContainer(int n) {
		System.out.println("Generazione Container");
		ArrayList<String> listaImo = queryToArrayList("SELECT nave FROM Viaggio", "nave");
		ArrayList<String> listaLocode = queryToArrayList("SELECT LOCODE FROM Porto", "LOCODE");
		Calendar oggi = new GregorianCalendar();
		int i = 0;
		while(i < n){
			Calendar d = new GregorianCalendar((oggi.get(Calendar.YEAR) - 1), r.nextInt(12), r.nextInt(28)+1 );
			int bic = Integer.parseInt(String.valueOf(r.nextInt(1000)) + i*1000);
			String categoria = r.nextInt(10) + generaLettere(1);
			int nave =  Integer.parseInt(listaImo.get(r.nextInt(listaImo.size())));
			String portoP= listaLocode.get(r.nextInt(listaLocode.size()));
			String portoA= listaLocode.get(r.nextInt(listaLocode.size()));
			String dataP = d.get(Calendar.YEAR)+ "-" + (d.get(Calendar.MONTH)+1) + "-"  + d.get(Calendar.DATE);
			if(r.nextBoolean()) {
				if(insertContainer(bic, categoria, nave, portoP, dataP, portoA))
					i++;
			}else {
				if(insertContainer(bic, categoria, portoP, dataP, portoA))
					i++;
			}
		}
	}
	
	public void generaProprietari(int n) {
		System.out.println("Generazione Proprietari");
		ArrayList<String> listaBIC= queryToArrayList("SELECT BIC FROM Container", "BIC");
		ArrayList<String> listaClienti= queryToArrayList("SELECT CF FROM Cliente", "CF");
		int i = 0;
		while(i < n){
			int bic = Integer.parseInt( listaBIC.get( r.nextInt( listaBIC.size() ) ) );
			String persona= listaClienti.get(r.nextInt(listaClienti.size()));

			if(insertProprietario(bic, persona))
				i++;	
		}
	}
	
	public void generaViaggi(int n) {
		System.out.println("Generazione Viaggi");
		ArrayList<String> listaImo = queryToArrayList("SELECT IMO FROM Nave", "IMO");
		ArrayList<String> listaLocode = queryToArrayList("SELECT LOCODE FROM Porto", "LOCODE");
		Calendar oggi = new GregorianCalendar();
		int i = 0;
		while(i < n){
			Calendar d = new GregorianCalendar((oggi.get(Calendar.YEAR) - 1), r.nextInt(12), r.nextInt(28)+1 );
			String dataDiInizio =  d.get(Calendar.YEAR)+ "-" + (d.get(Calendar.MONTH)+1) + "-"  + d.get(Calendar.DATE);
			int nave = Integer.parseInt(listaImo.get(r.nextInt(listaImo.size())));
			String portoP= listaLocode.get(r.nextInt(listaLocode.size()));
			String portoA= listaLocode.get(r.nextInt(listaLocode.size()));

			if(insertViaggio(dataDiInizio, nave, portoP, portoA))
				i++;
		}
	}

	public void generaTabelle() {
		deleteAllTable();
		//Base
		generaPorti(200);
		generaNavi(100);
		generaClienti(150);
		generaBroker(20);
		generaAmministratori(40);
		
		//Derivati
		generaViaggi(200);
		generaContainer(500);
		generaProprietari(500);
		generaScali(40);
		System.out.println("Generazione Terminata!");
	}


	private void fileToArray(String nomef, ArrayList<String> x) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(nomef));
		while(sc.hasNext())
			x.add(sc.next());
		sc.close();
	}

	private String generaLettere(int n) {
		String alfabeto = "QWERTYUIOPASDFGHJKLZXCVBNM";
		String out = "";
		for(int i=0; i<n; i++) {
			out += alfabeto.charAt(r.nextInt(alfabeto.length()));
		}
		return out;
	}

	private ArrayList<String> queryToArrayList(String query, String colonna){
		ArrayList<String> x = new ArrayList<>();
		try {
			ResultSet risultato = stmt.executeQuery(query);
			while(risultato.next())
				x.add(risultato.getString(colonna));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return x;
	}
	
	public int getColumnCount(String nome) {
		try {
			ResultSet risultato = stmt.executeQuery("Select * from " + nome + ";");
			ResultSetMetaData metadata = risultato.getMetaData();
			return metadata.getColumnCount();	
		} catch (SQLException e) {
			e.printStackTrace();
			return -1;
		}	
	}
	
	public String getColumnName(String nome) {
		try {
			ResultSet risultato = stmt.executeQuery("Select * from " + nome + ";");
			ResultSetMetaData metadata = risultato.getMetaData();
			int nColonne = metadata.getColumnCount();
			String out = "";
			for(int i=1; i<=nColonne; i++) {
				out += metadata.getColumnName(i);
				if(i == nColonne)
					out += "\n";
				else
					out += "-";
			}
			return out;
		} catch (SQLException e) {
			e.printStackTrace();
			return "";
		}	
	}
	
	public String queryToText(String query){
		String out = "";
		try {
			ResultSet risultato = stmt.executeQuery(query);
			ResultSetMetaData metadata = risultato.getMetaData();
			int nColonne = metadata.getColumnCount();
			
			for(int i=1; i<=nColonne; i++) {
				out += metadata.getColumnName(i);
				if(i == nColonne)
					out += "\n";
				else
					out += "\t";
			}
			
			while(risultato.next()) {
				for(int i=1; i<= nColonne; i++) {
					out += risultato.getString(i);
					if(i == nColonne)
						out += "\n";
					else
						out += "\t";
				}
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return out;
	}
	
//	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("Nomi.txt"));
//		PrintStream pt = new PrintStream("Nomi1.txt");
//		while(sc.hasNext()) {
//			String x = sc.next();
//			if(x.length() < 10) {
//				pt.println(x);
//			}
//		}
//	}
	
//	public static void main(String[] args) throws SQLException {
//		DB db = new DB("root", "@Kaliffo1", "dbprog");
//		db.deleteTable("Scalo");
//		db.generaScali(200);
//	}
	
}
