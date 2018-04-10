//
// Created by Tooster on 10.04.2018.
//

#include <iostream>
#include "expressions/expression.h"
#include "expressions/unary/sin.h"
#include "expressions/nullary/Phi.h"
#include "expressions/binary/sub.h"
#include "expressions/nullary/pi.h"
#include "expressions/binary/add.h"
#include "expressions/nullary/num.h"
#include "expressions/binary/mul.h"
#include "expressions/nullary/var.h"
#include "expressions/nullary/e.h"
#include "expressions/unary/cos.h"
#include "expressions/unary/exp.h"
#include "expressions/unary/ln.h"
#include "expressions/unary/abs.h"
#include "expressions/unary/addInv.h"
#include "expressions/unary/mulInv.h"
#include "expressions/binary/div.h"
#include "expressions/binary/log.h"
#include "expressions/binary/mod.h"
#include "expressions/binary/pow.h"

using namespace std;

void pr_var() {
    auto vx = Var::getVars();
    cout << "variables: {";
    for (auto v: vx) cout << "\t`" << v.first << ":" << v.second;
    cout << "}" << endl;
}

void pr(Expression *e) {
    cout << e->toString() << "\t=\t" << e->eval() << endl;
}

void demo() {
    cout << endl << "\t-= DEMO =-" << endl;
    Var::setVar("x", 10);
    Var::setVar("y", 200);
    Var::setVar("z", 3000);

    pr_var();
    auto dmm = new Var("x");
    pr(new Num(7));
    pr(new Pi());
    pr(new E());
    pr(new Phi());
    pr(new Var("x"));
    pr(new Sin(dmm));
    pr(new Cos(dmm));
    pr(new Exp(dmm));
    pr(new Ln(dmm));
    pr(new Abs(dmm));
    pr(new AddInv(dmm));
    pr(new MulInv(dmm));
    pr(new Add(dmm, dmm));
    pr(new Sub(dmm, dmm));
    pr(new Mul(dmm, dmm));
    pr(new Div(dmm, dmm));
    pr(new Log(dmm, dmm));
    pr(new Mod(dmm, dmm));
    pr(new Pow(dmm, dmm));
    cout << "\t-= DEMO END =-" << endl << endl;
    cout.flush();

}

int main() {
    demo();
    pr(new Sin(new Phi()));
    pr(new Sub(new Pi(), new Add(new Num(2), new Mul(new Var("x"), new Num(7)))));

    auto e1 = new Div(
            new Mul(
                    new Sub(
                            new Var("x"),
                            new Num(1)),
                    new Var("x")),
            new Num(2));

    auto e2 = new Div(
            new Add(
                    new Num(3),
                    new Num(5)),
            new Add(
                    new Num(2),
                    new Mul(
                            new Var("x"),
                            new Num(7))));

    auto e3 = new Sub(
            new Add(
                    new Num(2),
                    new Mul(
                            new Var("x"),
                            new Num(7))),
            new Add(
                    new Mul(
                            new Var("x"),
                            new Num(3)),
                    new Num(5)));

    auto e4 = new Div(
            new Cos(
                    new Mul(
                            new Add(
                                    new Var("x"),
                                    new Num(1)
                            ),
                            new Var("x")
                    )
            ),
            new Pow(
                    new E(),
                    new Pow(
                            new Var("x"),
                            new Num(2)
                    )
            )
    );

    cout << std::fixed;
    cout.precision(3);
    for (double i = 0.00; i < 1.00; i += 0.02) {
        Var::setVar("x", i);
        cout << "x = " << Var::getVar("x") << ":\t"
             << e1->eval() << "\t"
             << e2->eval() << "\t"
             << e3->eval() << "\t"
             << e4->eval() << endl;
    }

}