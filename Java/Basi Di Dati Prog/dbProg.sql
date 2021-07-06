drop database if exists dbProg;
create database dbProg;
use dbProg;

create table Cliente (
	CF char(16) primary key,
	nome varchar(50) not null,
	cognome varchar(50) not null,
    dataNascita date not null
);

create table Broker (
	CF char(16) primary key,
	nome varchar(50) not null,
	cognome varchar(50) not null,
    dataNascita date not null,
    matricola varchar(50) default null
);

create table Amministratore(
	dataInizio date,
    dataFine date,
	broker char(16) references Broker(CF) on update cascade on delete cascade,
    nave numeric(50) references Nave(IMO) on update cascade on delete cascade,
    primary key (dataInizio, dataFine, broker, nave)
);

create table Nave(
	IMO numeric(50) primary key,
	effContainer numeric(5) not null,
    maxContainer numeric(5) not null,
    lunghezza double not null,
    larghezza double not null,
    pescaggio double not null,
    annoCostruzione numeric(4) not null
);

create table Viaggio(
	dataInizio date,
    nave numeric(50) references Nave(IMO) on update cascade on delete cascade,
    portoPartenza char(6) not null references Porto(LOCODE) on update cascade on delete cascade,
    portoArrivo char(6) not null references Porto(LOCODE) on update cascade on delete cascade,
    primary key (dataInizio, nave)
);

create table Porto(
	LOCODE char(6) primary key,
    nome varchar(50) not null
);

create table Proprietario(
	container numeric(50) references Container(BIC) on update cascade on delete cascade,
    cliente char(16) references cliente(CF) on update cascade on delete cascade,
    primary key (Container, cliente)
);

create table Container(
	BIC numeric(50) primary key,
    categoria varchar(50) not null,
    nave numeric(50) default null references Nave(IMO) on update cascade on delete cascade,
    portoPartenza char(6) not null references Porto(LOCODE) on update cascade on delete cascade,
	dataPartenza date,
    portoArrivo char(6) not null references Porto(LOCODE) on update cascade on delete cascade
);

create table Scalo(
	porto char(6) not null references Porto(LOCODE) on update cascade on delete cascade,
    viaggio date not null references Viaggio(dataDiInizio) on update cascade on delete cascade,
    nave numeric(50) not null references Nave(IMO) on update cascade on delete cascade,
    primary key(porto, viaggio, nave)
);

/*-----------------------------------------------------------------------------------------------------------------------------------*\
|Esempi di inserimento.																												  |
|------------------------------------------------------------------------------------------------------------------------------------ |
|Inserimento Clienti																												  |
|insert into Persona(CF,nome, cognome, dataNascita) value ("H100F", "MELANIA", "DOMENICONI", "1988-12-9");							  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Broker							  																						  |
|insert into Persona(CF,nome, cognome, dataNascita, matricola) value ("A100M", "FULVIA", "MATROUF", "1992-7-25", "0");				  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Nave							  																						  |
|insert into Nave value (123456789, 100, 200, 120.12, 15.0, 9.0, 1999);							  									  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Proprietario							  																				  |
|insert into Proprietario value (123456789, "H100F");							  													  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Container							  																					  |
|insert into Container value (123456789, "1A", "IT POZ", "IT NAP");							  										  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Amministratore							  																				  |
|insert into Amministratore value ("2019-12-01", "2019-12-31", "H100F", 123456789);							  						  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Porto							 																						  |
|insert into Porto value ("IT POZ", "Pozzuoli");																					  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Scalo							  																						  |
|insert into Scalo value ("IT POZ", "2019-12-01, 123456789);							 											  |
|-------------------------------------------------------------------------------------------------------------------------------------|
|Inserimento Viaggio																												  |
|insert into Viaggio value ("2019-12-01", 123456789, "IT POZ", "IT NAP");															  |
\*-----------------------------------------------------------------------------------------------------------------------------------*/