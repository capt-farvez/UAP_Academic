father(reza, joynal).
father(joynal, siraj).

father(siraj, mendi).
father(mendi, nurul).
father(nurul, abdul).
father(nurul, jalil).
father(abdul, anowar).
father(abdul, nayeem).
father(jalil, rashed).

father(mendi, kader).
father(kader, johir).
father(kader, kobir).
father(johir, mohin).
father(kobir, poly).

father(siraj, goni).
father(goni, rofiq).
father(rofiq, kalam).
father(rofiq, zafor).
father(kalam, naju).
father(zafor, shuvo).

father(joynal, rashid).
father(rashid, ahsan).
father(ahsan, kamal).
father(kamal, nejam).
father(nejam, rimel).

father(reza, selim).
father(selim, hasan).
father(hasan, mustaq).
father(mustaq, mujahid).
father(mujahid, rana).
father(rana, tain).

mother(maria, joynal).

mother(ambia, siraj).
mother(masuma, mendi).

mother(razia, nurul).
mother(nesa, abdul).
mother(nesa , jolil).
mother(saheda, anowar).
mother(monowara, rashed).

mother(razia, kader).
mother(rahima, johir).
mother(rahima, kobir).
mother(habiba, mohin).
mother(popi, poly).

mother(masuma, goni).
mother(peyara, rofiq).
mother(rahima, kalam).
mother(rahima, zafor).
mother(beauti, naju).
mother(parul, shuvo).

mother(ambia, rashid).
mother(tahira, ahsan).
mother(sagorika, kamal).
mother(najia, nejam).
mother(rahela, rimel).

mother(maria, selim).
mother(ratna, hasan).
mother(jesia, mustaq).
mother(ruma, mujahid).
mother(samia, rana).
mother(ananna, tain).


parent(X,Y):-
    mother(X,Y);
    father(X,Y).

sibling(X,Y):-
    parent(Z,X),
    parent(Z,Y),
    X\=Y.


grandparent(X,Y) :-
    parent(X,Z),
    parent(Z,Y).

greatgrandparent(X,Y) :-
    parent(X,Z),
    grandparent(Z,Y).

greatgreatgrandparent(X, Y) :-
    parent(X, Z),
    greatgrandparent(Z, Y).

greatgreatgreatgrandparent(X, Y) :-
    parent(X, Z),
    greatgreatgrandparent(Z, Y).

fourthgreatgrandparent(X, Y) :-
    parent(X, Z),
    greatgreatgreatgrandparent(Z, Y).



firstcousin(X,Y):-
     parent(A,X),
     parent(B,Y),
     sibling(A,B).    

secondcousin(X,Y):-
    grandparent(A,X),
    grandparent(B,Y),
    sibling(A,B).
	
thirdcousin(X,Y):-
    greatgrandparent(A,X),
    greatgrandparent(B,Y),
    sibling(A,B).



firstcousin_onceremoved(X,Y):-
    parent(Z,Y),
    firstcousin(X,Z).

firstcousin_twiceremoved(X,Y):-
    firstcousin(X,Z), 
    grandparent(Z,Y).

firstcousin_thriceremoved(X,Y):-
    firstcousin(X,Z), 
    greatgrandparent(Z,Y).    

firstcousin_forthremoved(X,Y):-
    firstcousin(X,Z), 
    greatgreatgrandparent(Z,Y).      

secondcousin_onceremoved(X,Y):-
    parent(Z,Y), 
    secondcousin(X,Z).
 
secondcousin_twiceremoved(X,Y):-
    secondcousin(X,Z), 
    grandparent(Z,Y).

secondcousin_thriceremoved(X,Y):-
    secondcousin(X,Z), 
    greatgrandparent(Z,Y).

thirdcousin_onceremoved(X,Y):-
    parent(Z,Y), 
    thirdcousin(X,Z).

thirdcousin_twiceremoved(X,Y):-
    thirdcousin(X,Z), 
    grandparent(Z,Y).
