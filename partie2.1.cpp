/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#define PI 3.14159
double eps =5 ;
double gam = 20;
double lam =1;
double a=100 ;
double  b = 11;
using namespace std;

/*********************
 * 2.1  Les neouds Projet CalculScientifique
 * ***/
// Question 3
double x;
double y;
double w;
double ug(double y){

    return sin(PI*y);
}

double ud(double y){
    return 0;
}

double ug_derivs(double y){
    return -pow(PI,2)*sin(PI*y);
}

double ud_derivs(double y){

    return 0;
}
//ud_derivs et ug_derivs sont les fonctions derivés secondes de u*
double fsecond_membre( double x, double y  ) {
int a = 1;
    double r =(eps*((x+a)*ud_derivs(y)- (x-a)*ug_derivs(y) )  - gam*(ud(y) - ug(y))
            - lam*( (x+a)*ud(y) -(x-a)*ug(y)) )/(2*a) ;

     return r;

}



//Question 9 ecrivons la fonction subdiv
vector <double> Subdiv (double a, int N){
     // h represente le pas
    double h = 2*a/N;
     // xi va contenir toutes les point x1.....xN
    vector <double> xi = vector<double>(N+1) ;
    // cette boucle permet de faire le calcul des xi
     for (int i = 0; i<=N ; i++){

        xi[i]=-a + i*h;
     }

     return xi;
}

int numgb (int N, int M , int i, int j ){

     int sij = (N+1)*j+i;

     return sij;
}

//Question 13

vector <int> invnumgb(int N, int M, int s ){

    vector <int> resultat ;
    bool t_test=false;
    if( 0 <= s && s<= (N+1)*(M+1)-1 ){

        for(int i = 0; i<=N; i++){

            for(int j = 0; j<=M; j++){

                if( s==numgb(N, M,i,j)) {

                    resultat.push_back(i);
                    resultat.push_back(j);
                    t_test=true;
                    break;

                }

            }
            if (t_test) break;
        }
    }
    return resultat ;
}

/************
 *  Partie 2.1.2 du projet calcul Scientifique UVSQ
**/

//queston (14)

int  numint(int N, int M, int i, int j){
     //condition ou le i et le j ne verifie pas la condition
    if( (i< 1 || i > N-1) && (j< 1 || j > N-1) ){

        return -1;
    }

    else {
        return ((j-1)*(N-1)+i-1);
    }
}

//question(16)

vector<int> invnumint(int N , int M, int k){

    vector <int> resultat ;
    bool t_test=false;
    if(  k>0 && k <= (N-1)*(M-1)-1 ){
        for(int i = 1; i< N; i++){

            for(int j = 1; j<M; j++){

                if( k==numint(N, M,i,j) ) {

                    resultat.push_back(i);
                    resultat.push_back(j);

                    t_test=true;
                    break;
                }

            }
            if (t_test) break;
        }
    }
    return resultat ;
}

//question 17

int num_int_gb(int N, int M, int k){
    vector<int> vecteur;

    if(0 <= k && k <= (N-1)*(M-1)-1){
        vecteur = invnumint(N ,M, k);
    }
    return numgb(N,M,vecteur[0],vecteur[1]);
}

//question 18

int num_gb_int(int N, int M, int s){

    vector<int> m_vecteur = invnumgb(N ,M, s);

    return numint(N,M,m_vecteur[0],m_vecteur[1]);
}

// 2.2 Partie triangulation

//fonction de mallage

 vector<vector<int> > maillageTR(int N, int M){

    vector<vector<int> > TGR ;

     vector<int> t_1 (3);
     vector<int> t_2 (3);
     vector<int> t_11 (3);
     vector<int> t_22 (3);
// incrementation de 2 pas pour pouvoir alterner les triangles horizontalement et verticalement
    for(int j=0; j<M; j=j+2){

        for(int i=0; i<N; i=i+2){


            t_1[0] =  numgb(N,M,i,j);
            t_1[1] = numgb(N,M,i+1,j);
            t_1[2] = numgb(N,M,i,j+1);

            t_2[0] = numgb(N,M,i+1,j);
            t_2[1] = numgb(N,M,i,j+1);
            t_2[2] = numgb(N,M,i+1,j+1);

            TGR.push_back(t_1);
            TGR.push_back(t_2);

            t_11[0] =  numgb(N,M,i+1,j);
            t_11[1] = numgb(N,M,i+2,j);
            t_11[2] = numgb(N,M,i+2,j+1);

            t_22[0] = numgb(N,M,i+1,j);
            t_22[1] = numgb(N,M,i+1,j+1);
            t_22[2] = numgb(N,M,i+2,j+1);
            TGR.push_back(t_11);
            TGR.push_back(t_22);



        }




          for(int i=0; i<N; i=i+2){



              t_22[0] =  numgb(N,M,i,j+1);
              t_22[1] = numgb(N,M,i+1,j+1);
              t_22[2] = numgb(N,M,i+1,j+2);

              t_11[0] = numgb(N,M,i,j+1);
              t_11[1] = numgb(N,M,i,j+2);
              t_11[2] = numgb(N,M,i+1,j+2);
              TGR.push_back(t_11);
              TGR.push_back(t_22);


              t_2[0] =  numgb(N,M,i+1,j+1);
              t_2[1] = numgb(N,M,i+2,j+1);
              t_2[2] = numgb(N,M,i+1,j+2);

              t_1[0] = numgb(N,M,i+2,j+1);
              t_1[1] = numgb(N,M,i+1,j+2);
              t_1[2] = numgb(N,M,i+2,j+2);

            TGR.push_back(t_1);
            TGR.push_back(t_2);

        }
        /*

        for(int i=0; i<N; i++){


            t_1[0] =  numgb(N,M,i,j+1);
            t_1[1] = numgb(N,M,i+1,j+1);
            t_1[2] = numgb(N,M,i+1,j+2);

            t_2[0] = numgb(N,M,i,j+1);
            t_2[1] = numgb(N,M,i,j+2);
            t_2[2] = numgb(N,M,i+1,j+2);

            TGR.push_back(t_1);
            TGR.push_back(t_2);
        }
*/
    }


     return TGR;
}


//question (31):

vector < vector <double> > CalcMatBTt(vector<double> xs, vector<double> ys ){

	vector < vector <double> >  mat;

	mat.push_back(vector <double> (2) );

	mat.push_back(vector <double> (2) ) ;
    //coefficient de la matrice BT
	mat[0][0] = xs[1] - xs[0];

	mat[0][1] = xs[2] - xs[0];

	mat[1][0] = ys[1] - ys[0];

	mat[1][1] = ys[2] - ys[0];


	return mat;

}

//question 37 :

 // cette fonction permet de calculer la matrice inverse de B_T

 vector <vector <double> > BT_inv ( vector <vector <double> >   M,double determinant){

     vector < vector <double> >  matri;

     matri.push_back(vector <double> (2) );
     matri.push_back(vector <double> (2) ) ;
     matri[0][0] = (1/determinant)*M[1][1];

     matri[0][1] = -(1/determinant)*M[0][1];

     matri[1][0] = -(1/determinant)*M[1][0];

     matri[1][1] = (1/determinant)*M[0][0] ;

     return   matri;


 }

 //Transpose de la matrice inverse de BT
vector <vector <double> > BT_inv_t ( vector <vector <double> >   M){

    vector < vector <double> >  matri;

    matri.push_back(vector <double> (2) );
    matri.push_back(vector <double> (2) ) ;
    matri[0][0] = M[1][1];

    matri[1][0] = -M[0][1];

    matri[0][1] = -M[1][0];

    matri[1][1] = M[0][0] ;

    return   matri;


}
//calcul du produit de deux matrices inverse de BT et BT transpose

vector<vector<double>> produit_matrice(vector<vector<double>> A, vector<vector<double>> B,vector<vector<double>> &P ){

    P = vector<vector<double>>(2);
    vector<double>p(2) ;
    for (int i=0; i<2; i++){

        for (int j=0; j<2; j++){
            double s =0 ;
            for (int k=0; k<2; k++){

                s = s + A[i][k]*B[k][j]; }

            p[j]=s;
        }
        P[i] = p;

    }
    return P;

}

//Produit de vecteur-matrice
vector<double> produit_vecteur_matrice(vector<vector<double>>m,  vector<double> v ,vector<double> &resultat)
{
    resultat = vector<double>(v.size());
    double s ;

    for(int j=0; j<2; j++)
    {
        s = 0 ;
        for(int i=0;i<2;i++)
            s += m[j][i]*v[i] ;
        resultat[j] = s ;
    }
    return resultat;
}

//Produit matrice vecteurs
vector<double> produit_matrice_vecteur(vector<vector<double>>m,  vector<double> v ,vector<double> &resultat)
{
    resultat = vector<double>(v.size());
    double s ;

    for(int j=0; j<2; j++)
    {
        s = 0 ;
        for(int i=0;i<2;i++)
            s += m[i][j]*v[i] ;
        resultat[j] = s ;
    }
    return resultat;
}

vector<vector <double> > DiffTerm ( vector<double> xs , vector<double> ys ) {

   vector <vector<double>> matrice;

    vector<double> ligne(3);

   double det = (xs[1]-xs[0])*(ys[2]-ys[0]) - (xs[2]-xs[0])*(ys[1]-ys[0]);

    vector<vector<double>> B = CalcMatBTt(xs,ys);

    vector<vector<double>> B1 = BT_inv(B, det);

    vector<vector<double>> B2 = BT_inv_t(B1);

    // Les gradientlamdai chapeau pour 0<=i<=2
    vector<double> gradient_0 = {-1, -1};
    vector<double> gradient_1 = {1, 0};
    vector<double> gradient_2 = {0, 1};
    vector<vector<double> > gradient = {gradient_0, gradient_1, gradient_2};
    vector<vector<double> > grad;
    //cette boucle calcul les gradient lamda k transpose multiplie par les lamda j
    //vector< vector<double> > p = produit_matrice(B1,B2);
    vector<double> B3;
    vector<double> B33;

    for (int k = 0; k < 3; ++k) {

        for (int j = 0; j < 3; ++j) {

            vector<double> B4 =   produit_matrice_vecteur(B1,gradient[j], B3);
            vector<double> B5 =   produit_matrice_vecteur(B2,B4, B33);

         ligne[j]= inner_product( gradient[k].begin(),gradient[k].end(),B5.begin(), 0   );

        }
        matrice.push_back(ligne);
    }

      return matrice;

}
vector<vector <double> > ConvectTerm ( vector<double> xs , vector<double> ys ){
    double det = abs((xs[1]-xs[0])*(ys[2]-ys[0]) - (xs[2]-xs[0])*(ys[1]-ys[0]));
    vector<vector <double> > matrice ;
    vector<double> ligne(3);
    //lamda va contenir les integrales des lamdas chapeau pour j= 0,1 et 2
    vector <double> lamda {  -1/6, 1/6,1/6 };

    //lamda_k va contenir les integrales partiel de x des lamdas pour k= 0,1 et 2

    vector <double> lamda_k {-1,1, 0};

    for (int k = 0; k <3 ; ++k) {

        for (int j = 0; j < 3; ++j) {

            ligne[j]= det*lamda_k[k]*lamda[j];

        }
        matrice.push_back(ligne);
    }
    return matrice;}


vector<vector <double> > ReacTerm ( vector<double> xs , vector<double> ys ){
    double det = abs((xs[1] - xs[0])*(ys[2] - ys[0]) -(xs[2] - xs[0])*(ys[1] - ys[0]));
    vector<vector <double> > matrice ;

    vector <double> M0{ det/24,det/48, det/48 };
    vector <double> M1{ det/48,det/24, det/48 };
    vector <double> M2{ det/48,det/48 ,det/24 };

    matrice.push_back(M0);
    matrice.push_back(M1);
    matrice.push_back(M2);
    return matrice;
}











int N;
int M;



/*
vector <int> extendVec (vector<int> V ){

	int I = (N-1)*(M-1);
	int G = (N+1)*(M+1);

	vector <int> V_f (G);

	for (int i = 0 ; i < G ; i++){



	}
	}

*/

//question 2.2.2 (31)



// Partie (44)

// question (d)

vector <double> extendVect(vector <double> V, int N=6, int M=6){

    int I = V.size();
    int G = (N+1)*(M+1);
    vector <double> W(G);
    int k=0;

    for (int s = 0; s < G; s++)
    {
        int k=num_gb_int(M,N,s);
        if(k!=-1){
            W[s]=V[k];
        }else
        {
            W[s]=0;
        }
        k++;
    }

    return W;
}

// question (e)
vector<double> intVect(vector <double> W, int N=6, int M=6){

    int I = (N-1)*(M-1);
    int G = W.size();
    vector <double> V(I);
    int k=0;

    for (int s = 0; s < G; s++)
    {
        int k=num_gb_int(M,N,s);
        if(-1!=k){
            V[k]=W[s];
        }
        k++;
    }
    return V;
}

//question 10


int TRG(int t, int i, int N, int M){

    int n_trg=0;
    vector<vector<int>> liste_trg;
    vector<int> t_trg;
    int glb=0;

    if(i <= 2)
    {
        liste_trg = maillageTR(N, M);
        t_trg = liste_trg[t];
        glb=t_trg [i];
    }
    return glb;
}

vector <double>  matVec(vector <double> v, int K, double a=1, int N=6, int M= 6){

    vector <double>  WW((N+1)*(M+1)) ;


    vector <vector <int> > B;

    vector<double> W;

    int s=0;

    double b=a;


    for (int t= 0 ; t <= K-1 ; t++){

        vector <double> xs, ys;

        vector <int>  t_trg;

        vector <double> lesXs= Subdiv (a, N);

        vector <double> lesYs= Subdiv (b, M);

        t_trg=(maillageTR(N,M))[t];
        vector <int> V1= invnumgb(M,N,t_trg[0]);
        vector <int> V2= invnumgb(M,N,t_trg[1]);
        vector <int> V3= invnumgb(M,N,t_trg[2]);

        // la matrice jacobienne
        for (int i = 0; i <=2; i++)
        {
            xs.push_back(lesXs[V1[0]]);
            xs.push_back(lesXs[V2[0]]);
            xs.push_back(lesXs[V3[0]]);
        }

        for (int i = 0; i <=2; i++)
        {
            ys.push_back(lesYs[V1[1]]);
            ys.push_back(lesYs[V2[1]]);
            ys.push_back(lesYs[V3[1]]);
        }

        vector <vector <double>> matrix_g= CalcMatBTt(xs,ys);
        for (int i = 0; i <= 2; i++)
        {
            s=TRG(t,i,N,M);

            double res ;

            for (int j = 0; j <= 2 ; i++)
            {
                int r = TRG(t,j, N, M);


                double PROD2 = eps* DiffTerm(xs,ys)[i][j]+gam* ConvectTerm(xs,ys)[i][j]+lam*ReacTerm(xs,ys)[i][j];



                res= res + extendVect(v,N,M)[r]*PROD2;

            }

            WW[s]= WW[s] + res;
        }
    }

    W=intVect(WW);

    return W;
}


int main() {

    cout << "******************numgb********************\n" << endl;
    int re = numgb(10, 14,5, 3);
    cout << re << "\n" << endl;
    cout << "******************invnumgb********************\n" << endl;

    vector<int> result = invnumgb(10, 10, 38);
    cout << "(" << result[0] << "," << result[1] << ")" << "\n" << endl;

    cout << "******************numint********************\n" << endl;

    cout << numint(10, 14, 5, 3) << endl;
    cout << "\n" << endl;


    cout << "******************invnumint********************\n" << endl;
    cout << "Trouvons les valeurs de i et j\n" << endl;
    vector<int> invnumin = invnumint(10, 14, 22);
    cout << "(" << invnumin[0] << "," << invnumin[1] << ")" << "\n" << endl;
    cout << "******************num_int_gb********************\n" << endl;
    cout << "La valeur globale  est \n" << endl;
    cout << num_int_gb(10, 14, 12) << endl;
    cout << "\n" << endl;
    cout << "******************num_gb_int********************\n" << endl;
    cout << "Le numero interieur globale est :  k\n" << endl;

    cout << num_gb_int(10, 14, 26) << endl;

    cout << "***************************************************************************\n" << endl;

    cout << "question 31: calcul de la matrice Bt\n" << endl;
    vector<double> x(3);
    vector<double> y(3);
    x[0] = 1;
    x[1] = 3;
    x[2] = 2;
    y[0] = 3;
    y[1] = 8;
    y[2] = 6;

    vector<vector<double> > Bt = CalcMatBTt(x, y);
    vector<double> m0 = Bt[0];
    vector<double> m1 = Bt[1];
    cout << "La matrice bt est :  \n" << endl;

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {

            cout << Bt[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "La matrice bt inv est :  \n" << endl;
    double d = abs((x[1] - x[0])*(y[2] - y[0]) -(x[2] - x[0])*(y[1] - y[0]));
    vector<vector<double>> Bt_I = BT_inv(CalcMatBTt(x, y), d);

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {

            cout << Bt_I[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "La matrice bt inv_t est :  \n" << endl;
    vector<vector<double>> Bt_I_INV = BT_inv_t(Bt_I);
    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {

            cout << Bt_I_INV[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "LE produit de matrice vecteur :  \n" << endl;
    vector<double> bb{2,3};
    vector <double> resultat;
    produit_matrice_vecteur(Bt_I,bb,resultat);
    for (int i = 0; i < 2; i++) {

        cout <<  resultat[i]<< "\t";

        cout << endl;
    }

    cout << "***********************Produit matriciel****************************** \n" << endl;
    vector<double> b11{1,4};
    vector<double> b12{2,2};
    vector<vector<double>> b1{b11, b12  };
    vector<double> a11{1,2};
    vector<double> a12{2,1};
    vector<vector<double>> a1{a11, a12 };
    vector<vector<double>> P;
    produit_matrice(a1, b1, P);

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j <2; j++) {

            cout << P[i][j] << "\t";
        }
        cout << endl;
    }


    cout << "***********************Le maillage****************************** \n" << endl;

    vector<vector<int> > maillage = maillageTR(10, 14);

    for (int i = 0; i < 2*14*10; i++) {
        cout <<"["<<endl;
        for (int j = 0; j <= 2; j++) {

            cout << maillage[i][j]<<"," << "\t";

        }
        cout <<"],"<< endl;
    }



    cout << "***********************Fonction DiffTerm******************** \n" << endl;

    vector< vector<double>> diff = DiffTerm(x,y);
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << diff[i][j] << "\t";

        }
        cout << endl;
    }

    cout << "***********************Fonction ReacTerm******************** \n" << endl;

    vector< vector<double>> dif = ReacTerm(x,y);
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << dif[i][j] << "\t";

        }
        cout << endl;
    }


    cout << "***********************Fonction ConvectTerm******************** \n" << endl;

    vector< vector<double>> convect = ConvectTerm(x,y);
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << convect[i][j] << "\t";

        }
        cout << endl;
    }


    cout << "***********************Subdiv******************** \n" << endl;
    vector<double> xi = Subdiv(1, 10);
    vector<double> yi = Subdiv(1, 14);
    cout << "Les valeurs de xi\n" << endl;
    for (int i= 0; i < 11; ++i) {
        cout << xi[i]<< endl;
    }

   cout << "Les valeurs de yi\n" << endl;

    for (int i= 0; i < 15; ++i) {
        cout << yi[i]<< endl;
    }

/*
    cout << "***********************Fonction extendvect******************** \n" << endl;
    vector<double> v {1,4,8,2,5,12,23,45,68,32,6,23,45,32,18,16,54};
    vector<double> vect = extendVect(v, 10,14);

    for (int i= 0; i < (10+1)*(14+1); ++i) {
        cout << vect[i]<< endl;
    }*/
}







