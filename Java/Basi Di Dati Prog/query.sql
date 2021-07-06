use dbprog;

/*Query n° 1
Trovare per tutti i container sprovvisti di viaggio una nave su cui poterli caricare. Si tenga in considerazione il fattore tempo.*/

Select v.nave as "Imo Nave", v.dataInizio as "Data di Partenza", c.bic as "BIC"
from (Scalo as s join Viaggio as v on s.nave = v.nave AND s.viaggio = v.dataInizio)join Container as c on c.dataPartenza <= v.dataInizio 
Where c.nave is NULL 
AND (c.portoPartenza = v.PortoPartenza  OR s.porto = c.portoPartenza ) AND (c.portoArrivo = v.PortoArrivo OR s.porto = c.portoArrivo);


/*Query n° 2
Visualizzare tutte le navi che hanno avuto almeno 2 amministratori */

Select n.imo, count(*) as "N_Amministratori" 
from amministratore as a join nave as n on a.nave = n.imo 
group by n.imo
having N_Amministratori > 2;


/*Query n° 3
Determinare la nave con il minor numero di viaggi.*/
with sub as (
	Select nave.imo as imo, count(*) as nViaggi from nave join viaggio on viaggio.nave = nave.imo GROUP BY nave.imo
)
select sub.imo #, nViaggi
from sub
where nViaggi = (select min(nViaggi) from sub);


/*Query n° 4
Trovare le navi che sono partite dal porto “x e non fanno scalo nel porto “y”.*/

Select * from viaggio 
where portoPartenza like "x" AND "y" not in (select porto from scalo where scalo.viaggio = viaggio.dataInizio and scalo.nave = viaggio.nave);


/*Query n° 5
Visualizzare i broker che hanno amministrato tutte le navi.*/

Select * from broker where not exists
	(select * from nave where not exists 
		(select * from amministratore where broker.cf = amministratore.broker AND amministratore.nave = nave.imo)
	);
