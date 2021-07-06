package GUI;

import java.awt.EventQueue;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import java.awt.CardLayout;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.GridLayout;
import javax.swing.JPasswordField;
import javax.swing.SwingConstants;

import Manipolazione.DB;

import java.awt.Font;
import java.sql.SQLException;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import java.awt.BorderLayout;
import javax.swing.JScrollPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class GUI {

	private JFrame frame;
	private JTextField username;
	private final JPanel panel_2 = new JPanel();
	private JPasswordField password;
	private JTextField dbname;
	
	private DB db;
	private JComboBox<String> table;
	private JTextArea textArea;
	private JTextField textCerca;
	private JTextField textElimina;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI window = new GUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public GUI() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 330, 330);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		CardLayout c = new CardLayout(0, 0);
		frame.getContentPane().setLayout(c);
		
		
		
//		frame.setSize(330, 330);											//Set Size Login
//		frame.setSize(820, 520);											//Set Size Utente
		JPanel login = new JPanel();
		frame.getContentPane().add(login, "Login");
		login.setLayout(new GridLayout(0, 1, 0, 0));
		
		JPanel panel = new JPanel();
		login.add(panel);
		
		JLabel lblText0 = new JLabel("Login");
		lblText0.setFont(new Font("Tahoma", Font.PLAIN, 40));
		panel.add(lblText0);
		
		JPanel panel_1 = new JPanel();
		login.add(panel_1);
		
		JLabel lblText1 = new JLabel("Username");
		panel_1.add(lblText1);
		
		username = new JTextField();
		username.setText("root");
		panel_1.add(username);
		username.setColumns(10);
		login.add(panel_2);
		
		JLabel lblText2 = new JLabel("Password");
		panel_2.add(lblText2);
		
		password = new JPasswordField();
		password.setText("");
		password.setColumns(10);
		panel_2.add(password);
		password.setToolTipText("");
		password.setHorizontalAlignment(SwingConstants.LEFT);
		
		JPanel panel_3 = new JPanel();
		login.add(panel_3);
		
		JLabel lblText3 = new JLabel("Database");
		panel_3.add(lblText3);
		
		dbname = new JTextField();
		dbname.setText("dbprog");
		panel_3.add(dbname);
		dbname.setColumns(10);
		
		JPanel panel_4 = new JPanel();
		login.add(panel_4);
		
		JButton btnLogin = new JButton("Login");
		panel_4.add(btnLogin);
		
		JPanel utente = new JPanel();
		frame.getContentPane().add(utente, "Utente");
		utente.setLayout(new BorderLayout(0, 0));
		
		JPanel panel_5 = new JPanel();
		utente.add(panel_5, BorderLayout.CENTER);
		
		JScrollPane scrollPane = new JScrollPane();
		panel_5.add(scrollPane);
		
		textArea = new JTextArea();
		textArea.setRows(20);
		textArea.setColumns(70);
		scrollPane.setViewportView(textArea);
		
		JPanel panel_6 = new JPanel();
		utente.add(panel_6, BorderLayout.SOUTH);
		panel_6.setLayout(new GridLayout(0, 1, 0, 0));
		
		JPanel panel_7 = new JPanel();
		panel_6.add(panel_7);
		
		table = new JComboBox<String>();
		panel_7.add(table);
		
		JButton btnAggiungi = new JButton("Aggiungi");
		panel_7.add(btnAggiungi);
		
		JButton btnMostraRicerca = new JButton("Mostra Ricerca");
		panel_7.add(btnMostraRicerca);
		
		JButton btnMostraElimina = new JButton("Mostra Elimina");
		panel_7.add(btnMostraElimina);
		
		JPanel panel_8 = new JPanel();
		panel_8.setVisible(false);
		panel_6.add(panel_8);
		
		textCerca = new JTextField();
		panel_8.add(textCerca);
		textCerca.setColumns(40);
		
		JButton btnCerca = new JButton("Cerca");
		panel_8.add(btnCerca);
		
		JButton btnCancella = new JButton("Cancella");
		panel_8.add(btnCancella);
		
		JPanel panel_9 = new JPanel();
		panel_9.setVisible(false);
		panel_6.add(panel_9);
		
		textElimina = new JTextField();
		textElimina.setColumns(40);
		panel_9.add(textElimina);
		
		JButton btnElimina = new JButton("Elimina");
		panel_9.add(btnElimina);
		
		JButton btnCancella1 = new JButton("Cancella");
		panel_9.add(btnCancella1);
		
		JPanel aggiungi = new JPanel();
		frame.getContentPane().add(aggiungi, "Aggiungi");
		aggiungi.setLayout(new BorderLayout(0, 0));
		
		JMenuBar menuBar = new JMenuBar();
		menuBar.setVisible(false);
		frame.setJMenuBar(menuBar);
		
		JMenu option = new JMenu("Opzioni");
		menuBar.add(option);
		
		JMenuItem logout = new JMenuItem("Logout");
		option.add(logout);
		
		JMenu genera = new JMenu("Genera");
		menuBar.add(genera);
		
		JMenuItem gPersona = new JMenuItem("Persone");
		genera.add(gPersona);
		
		JMenuItem gAmministratore = new JMenuItem("Amministratori");
		genera.add(gAmministratore);
		
		JMenuItem gNave = new JMenuItem("Navi");
		genera.add(gNave);
		
		JMenuItem gViaggio = new JMenuItem("Viaggi");
		genera.add(gViaggio);
		
		JMenuItem gPorto = new JMenuItem("Porti");
		genera.add(gPorto);
		
		JMenuItem gProprietario = new JMenuItem("Proprietari");
		genera.add(gProprietario);
		
		JMenuItem gContainer = new JMenuItem("Container");
		genera.add(gContainer);
		
		JMenuItem gScalo = new JMenuItem("Scali");
		genera.add(gScalo);
		
		JMenuItem generaTabelle = new JMenuItem("Completo");
		genera.add(generaTabelle);
	
		gPersona.addActionListener(e->{
			db.deleteTable("Persona");
			db.generaClienti(150);
			db.generaBroker(20);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gAmministratore.addActionListener(e->{
			db.deleteTable("Amministratore");
			db.generaAmministratori(40);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gNave.addActionListener(e->{
			db.deleteTable("Nave");
			db.generaNavi(100);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gViaggio.addActionListener(e->{
			db.deleteTable("Viaggio");
			db.generaViaggi(200);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gPorto.addActionListener(e->{
			db.deleteTable("Porto");
			db.generaPorti(200);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gProprietario.addActionListener(e->{
			db.deleteTable("Proprietario");
			db.generaProprietari(500);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gContainer.addActionListener(e->{
			db.deleteTable("Container");
			db.generaContainer(500);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		gScalo.addActionListener(e->{
			db.deleteTable("Scalo");
			db.generaScali(40);
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		generaTabelle.addActionListener(e -> {
			db.generaTabelle();
			resetTextArea();
			JOptionPane.showMessageDialog(frame.getContentPane(), "Generazione effettuata", "Conferma", JOptionPane.INFORMATION_MESSAGE);
		});
		
		table.addItem("Cliente");
		table.addItem("Broker");
		table.addItem("Amministratore");
		table.addItem("Nave");
		table.addItem("Viaggio");
		table.addItem("Porto");
		table.addItem("Proprietario");
		table.addItem("Container");
		table.addItem("Scalo");
		
		
		btnElimina.addActionListener(e->{
			if(textElimina.getText().compareTo("") == 0)
				db.deleteTable((String) table.getSelectedItem());
			else
				db.delete((String) table.getSelectedItem(), textElimina.getText());
			
			resetTextArea();
		});

		btnCancella1.addActionListener(e->{
			resetTextArea();
		});
		
		class Elimina implements ActionListener{
			private boolean mostra = false;
			public void actionPerformed(ActionEvent e) {
				if(!mostra) {
					mostra = true;
					btnMostraElimina.setText("Nascondi Elimina");
					panel_9.setVisible(true);
				}else {
					mostra = false;
					btnMostraElimina.setText("Mostra Elimina");
					textElimina.setText("");
					panel_9.setVisible(false);
				}
			}
		}
		btnMostraElimina.addActionListener(new Elimina());
		
		
		btnCancella.addActionListener(e -> {
			resetTextArea();
		});
		
		btnCerca.addActionListener(e -> {
			if(textCerca.getText().compareTo("") == 0)
				JOptionPane.showMessageDialog(frame.getContentPane(), "Ricerca non valida!", "Errore", JOptionPane.ERROR_MESSAGE);
			else {
				textArea.setText(db.queryToText("Select * from " + (String) table.getSelectedItem() + " WHERE " + textCerca.getText() + ";"));
			}
				
		});
		
		class Ricerca implements ActionListener{
			private boolean mostra = false;
			public void actionPerformed(ActionEvent e) {
				if(!mostra) {
					mostra = true;
					btnMostraRicerca.setText("Nascondi Ricerca");
					panel_8.setVisible(true);
				}else {
					mostra = false;
					btnMostraRicerca.setText("Mostra Ricerca");
					textCerca.setText("");
					panel_8.setVisible(false);
				}
			}
		}
		btnMostraRicerca.addActionListener(new Ricerca());
		
		
		btnAggiungi.addActionListener(e-> {
			c.show(frame.getContentPane(), "Aggiungi");
			int nColonne = db.getColumnCount( (String) table.getSelectedItem());
			String[] nomi = db.getColumnName( (String) table.getSelectedItem() ).split("-");
			JPanel[] dinamicGeneral = new JPanel[2];
			JPanel[] dinamicPanel = new JPanel[nColonne];
			JLabel[] dinamicText = new JLabel[nColonne];
			JTextField[] dinamicField = new JTextField[nColonne];
			
			dinamicGeneral[0] = new JPanel();
			dinamicGeneral[1] = new JPanel();
			aggiungi.add(dinamicGeneral[0], BorderLayout.CENTER);
			aggiungi.add(dinamicGeneral[1], BorderLayout.SOUTH);
			dinamicGeneral[0].setLayout(new GridLayout(0, 1));
			dinamicGeneral[1].setLayout(new FlowLayout());
			
			for(int i=0; i<nColonne; i++) {
				dinamicPanel[i] = new JPanel();
				dinamicPanel[i].setLayout(new FlowLayout());
				
				dinamicText[i] = new JLabel(nomi[i]);
				dinamicField[i] = new JTextField();
				dinamicField[i].setColumns(10);
				
				dinamicGeneral[0].add(dinamicPanel[i]);
				dinamicPanel[i].add(dinamicText[i]);
				dinamicPanel[i].add(dinamicField[i]);
			}
			
			JButton btnAnnulla = new JButton("Annulla");
			JButton btnConferma = new JButton("Conferma");
			
			btnAnnulla.addActionListener(el -> {
				aggiungi.removeAll();
				c.show(frame.getContentPane(), "Utente");
			});

			btnConferma.addActionListener(el -> {
				String[] dati = new String[nColonne];
				for(int i=0; i<nColonne; i++) {
					dati[i] = "";
					dati[i] += dinamicField[i].getText();
				}
				boolean stato = true;
				if(((String) table.getSelectedItem()).compareTo("Cliente") == 0) 
					stato = db.insertCliente(dati[0], dati[1], dati[2], dati[3]);
				else
					if(((String) table.getSelectedItem()).compareTo("Cliente") == 0)
						stato = db.insertBroker(dati[0], dati[1], dati[2], dati[3], dati[4]);
					else
						if(((String) table.getSelectedItem()).compareTo("Amministratore") == 0) {
							try {
								stato = db.insertAmministratori(dati[0], dati[1], dati[2], Integer.parseInt(dati[3]));
							}catch (NumberFormatException err) {
								JOptionPane.showMessageDialog(frame.getContentPane(), "Numero imo non valido", "Errore", JOptionPane.ERROR_MESSAGE);
							}
						}else
							if(((String) table.getSelectedItem()).compareTo("Nave") == 0) {
								try {
									stato = db.insertNavi(Integer.parseInt(dati[0]), Integer.parseInt(dati[1]), Integer.parseInt(dati[2]), Double.parseDouble(dati[3]), Double.parseDouble(dati[4]), Double.parseDouble(dati[5]), Integer.parseInt(dati[6]));
								}catch (NumberFormatException err) {
									JOptionPane.showMessageDialog(frame.getContentPane(), "Campi non validi", "Errore", JOptionPane.ERROR_MESSAGE);
								}
							}else	
								if(((String) table.getSelectedItem()).compareTo("Viaggio") == 0) {
									try {
										stato = db.insertViaggio(dati[0], Integer.parseInt(dati[1]), dati[2], dati[3]);
									}catch (NumberFormatException err) {
										JOptionPane.showMessageDialog(frame.getContentPane(), "Numero imo non valido", "Errore", JOptionPane.ERROR_MESSAGE);
									}
								}else
									if(((String) table.getSelectedItem()).compareTo("Porto") == 0)
										stato = db.insertPorto(dati[0], dati[1]);
									else if(((String) table.getSelectedItem()).compareTo("Proprietario") == 0) {
										try {
											stato = db.insertProprietario(Integer.parseInt(dati[0]), dati[1]);
										}catch (NumberFormatException err) {
											JOptionPane.showMessageDialog(frame.getContentPane(), "Numero bic non valido", "Errore", JOptionPane.ERROR_MESSAGE);
										}
									}else
										if(((String) table.getSelectedItem()).compareTo("Container") == 0) {
											try {
												stato = db.insertContainer(Integer.parseInt(dati[0]), dati[1], Integer.parseInt(dati[2]), dati[3], dati[4], dati[5]);
											}catch (NumberFormatException err) {
												JOptionPane.showMessageDialog(frame.getContentPane(), "Numero bic o numero imo non valido", "Errore", JOptionPane.ERROR_MESSAGE);
											}
										}
										else if(((String) table.getSelectedItem()).compareTo("Scalo") == 0)
											try {
												stato = db.insertScalo(dati[0], dati[1], Integer.parseInt(dati[2]));
											}catch (NumberFormatException err) {
												JOptionPane.showMessageDialog(frame.getContentPane(), "Numero imo non valido", "Errore", JOptionPane.ERROR_MESSAGE);
											}

				if(stato) {
					aggiungi.removeAll();
					c.show(frame.getContentPane(), "Utente");
					JOptionPane.showMessageDialog(frame.getContentPane(), "Inserimento riuscito", "Conferma", JOptionPane.INFORMATION_MESSAGE);
					resetTextArea();
				}else
					JOptionPane.showMessageDialog(frame.getContentPane(), "Inserimento non riuscito", "Errore", JOptionPane.ERROR_MESSAGE);
			});

			dinamicGeneral[1].add(btnAnnulla, BorderLayout.SOUTH);
			dinamicGeneral[1].add(btnConferma, BorderLayout.SOUTH);
		});

		table.addActionListener(e -> {
			resetTextArea();
		});

		btnLogin.addActionListener(e ->{
			try {
				db = new DB(username.getText(), String.valueOf(password.getPassword()), dbname.getText());
				c.show(frame.getContentPane(), "Utente");
				menuBar.setVisible(true);
				frame.setSize(820, 520);
				textArea.setText(db.queryToText("Select * from " + (String) table.getSelectedItem() + ";"));
				textArea.setCaretPosition(0);
			} catch (SQLException e1) {
				e1.printStackTrace();
				JOptionPane.showMessageDialog(frame.getContentPane(), "Credenziali non valide", "Errore", JOptionPane.ERROR_MESSAGE);
			}	

		});

		logout.addActionListener(e-> {
			try {
				db.close();
			} catch (SQLException e1) {
				JOptionPane.showMessageDialog(frame.getContentPane(), "Impossibile eseguire il logout", "Errore", JOptionPane.ERROR_MESSAGE);
			}
			c.show(frame.getContentPane(), "Login");
			menuBar.setVisible(false);
			frame.setSize(330, 330);
		});




	}

	private void resetTextArea() {
		textArea.setText(db.queryToText("Select * from " + (String) table.getSelectedItem() + ";"));
		textArea.setCaretPosition(0);
		textCerca.setText("");
		textElimina.setText("");
	}


}