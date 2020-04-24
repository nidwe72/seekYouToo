#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    setGeometry(0,0,400,600);

    QWidget* window=new QWidget;
    window->setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");

    QGridLayout* layout=new QGridLayout;
    window->setLayout(layout);

    lineEdit=new QLineEdit;
    buttonStart= new QPushButton("Start simulation");




    layout->addWidget(buttonStart,0,0,1,2);

    buttonStart->setStyleSheet("border-style: outset;border-width: 2px;border-radius: 4px;border-color: black;padding: 6px;");

    QLabel* pLabel = new QLabel();
    pLabel->setStyleSheet("QLabel { background-color : black; color : #76EE00; }");
    pLabel->setTextFormat(Qt::RichText);
    pLabel->setText("<center><b>Polyakov plaquette (avg.)</b></center>");
    pLabel->setMaximumHeight(40);

//    layout->addWidget(pLabel,2,0,1,2);

    SimulationExecutionPlan* executionPlan = SimulationExecutionPlanUtil::createFastExecutionPlan();

    SimulationWidget* simulationWidget=new SimulationWidget(this);
    layout->addWidget(simulationWidget,3,0,2,2);
    simulationWidget->setExecutionPlan(executionPlan);

    buttonStart->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    window->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QTabWidget* mainWidget=new QTabWidget();
    mainWidget->setStyleSheet("QTabWidget { background-color : #001a00; color : #76EE00; }");

//    QWebEngineView* buzz=this->test();
//    mainWidget->addTab(buzz,QString("Documentation"));

    //mainWidget->addTab(this->testWeb(),QString("Documentation"));


    /*
    QWidget* browserWidget=new QWidget();    
    browserWidget->setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");
    QGridLayout* bwl=new QGridLayout();
    bwl->setContentsMargins(0,0,0,0);
    browserWidget->setLayout(bwl);
    bwl->addWidget(QWidget::createWindowContainer(this->testWeb(),this),0,0);
    */






    //mainWidget->addTab(browserWidget,QString("Documentation"));

    mainWidget->addTab(QWidget::createWindowContainer(this->testWeb(),this),QString("Documentation"));




    mainWidget->addTab(window,QString("Simulation"));

    WilsonLoopByBetaChart* wilsonLoopByBetaChart = new WilsonLoopByBetaChart();

    mainWidget->addTab(wilsonLoopByBetaChart ,QString("Results"));

    setCentralWidget(mainWidget);
    setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");

    su3Simulation=new SU3Simulation(this);
    su3Simulation->setExecutionPlan(executionPlan);

    QObject::connect(buttonStart,&QPushButton::clicked,this,&MainWindow::on_buttonStart_clicked);

    QObject::connect(
        su3Simulation,
        &SU3Simulation::on_SimulationProgressSignal,
        simulationWidget,
        &SimulationWidget::handleSimulationProgressSignal,Qt::QueuedConnection);

    QObject::connect(
        su3Simulation,
        &SU3Simulation::on_SimulationMeasurementSignal,
        simulationWidget,
        &SimulationWidget::handleSimulationMeasurementSignal,Qt::QueuedConnection);

    QObject::connect(this,&MainWindow::signal_stopSimulation,su3Simulation,&SU3Simulation::stop);



}


MainWindow::~MainWindow()
{
    emit signal_stopSimulation();
}


void MainWindow::on_buttonStart_clicked()
{

    if(buttonStart->text()=="Start simulation"){
        buttonStart->setText("Stop simulation");
        simulationFuture=QtConcurrent::run(this->su3Simulation,&SU3Simulation::start);
    }else{
        buttonStart->setText("Start simulation");
        emit signal_stopSimulation();
    }

}


/*
QWebEngineView* MainWindow::test(){

    QWebEnginePage* page=new QWebEnginePage(QWebEngineProfile::defaultProfile());
    //page->setUrl(QUrl("https://www.mathjax.org/#samples"));



    page->setHtml(this->getDoc1());

    QWebEngineView* view=new QWebEngineView();
    view->setPage(page);

    return view;
}
*/

QString MainWindow::getDoc1(){
QString result(
R"Foo(
<html>
<head>
    <script type="text/javascript" async
        src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.4/MathJax.js?config=TeX-MML-AM_CHTML">
    </script>

<style>
    body{
        background-color: black;
        color: #66cc00;
    }

.accordion {
  background-color: #1a3300;
  color: #66cc00;
  cursor: pointer;
  padding: 18px;
  width: 100%;
  border: none;
  text-align: left;
  outline: none;
  font-size: 15px;
  transition: 0.4s;
}

.active, .accordion:hover {
  background-color: #1a3300;
}

.main{
    max-width:800px;
    /*text-align: center;*/
}

.panel {
  padding: 0 18px;
  display: none;
  /*background-color: white;*/
  overflow: hidden;
}
</style>

</head>
<body>


<div class="main">
[svg]

<h1>
<center>Quantum chromodynamics on your mobile device<br/>A layman's guide</center></h1>
<center>edwin.roth@gmx.at</center><br/>
Abstract.<b><i>Seek you too</i></b> let's you calculate properties of the 'strong force' acting between 'quarks' eventually building the nuclei of atoms.

<button class="accordion">A short history of physics</button>
<div class="panel">
<ul>
    <li>
When \(a \ne 0\), there are two solutions to \(ax^2 + bx + c = 0\) and they are
$$x = {-b \pm \sqrt{b^2-4ac} \over 2a}.$$
    </li>



               <li>
               In the 1660s Newton found that two particles with mass attract via the so-called gravitational force. This force is direct proportional to their masses and inverse proportional to the square of their distance.
               </li>

               <li>
               In the 1780s Coulomb stated an analogous law concerning electrically charged particles.
               </li>

               <li>
               In the 1810s Gauss found an equivalent formulation of Coulomb's law: The higher the charge of a particle, the higher the flux of the electric field through a surrounding volume.
               </li>

               <li>
               In the 1820s Ampere discovered that a helix of current-carrying wire acted like a permanent magnet.
               </li>

               <li>
               In the 1830ies Faraday discovered electromagnetic induction: Putting a coil being attached to a battery inside a larger coil without battery induces a current into the larger one.
               </li>

               <li>
               In the 1860s Maxwell proposed that light is an electromagnetic phenomena and formulated according equations. For instance Faraday's law in the form that a changing magnetic field changes the curl of the electric field.
               </li>

               <li>
               In the 1900ies Einstein stated that the speed of light in a vacuum is the same for all observers, regardless of the motion of the light source.
               In his Special Theory of Relativity he also finds that mass and energy are equivalent (E=mc²) and that mass is relative: a particle with nonzero rest mass
               (aka Netwonian mass) cannot travel at the speed of light because approaching this limit the particle's energy and momentum increases without bound.
               Only light (photons) having zero rest mass can travel with the speed of light.
               </li>

               <li>
               When light is shone onto a material electrons can be emitted,being called the photoelectric effect. In 1905 Albert published a paper advancing the hypothesis
               of Planck that light energy is carried in discrete quantized packets to explain experimental data from the photoelectric effect.
               </li>

               <li>
               In the sequel the theory of quantum mechanics was established by Planck, Bohr, Pauli, DeBroglie, Schrödinger, Dirac, Hilbert, Weyl and others.
               In this theory the state of a system at a given time is described by a wave function, an abstract mathematical object allowing for the calculation
               of probabilities for measurable properties such as location. For example, it allows one to compute the probability of finding an electron in a particular
               region around the nucleus of an atom: As a result the electrons de facto live in discrete shells having distinct energy levels.
               Shifting up an electron to the next shell requires exactly the corresponding energy difference, the according quantum so-to-speak, hence the name quantum mechanics.
               </li>

               <li>
               In the following quantization evolved: No longer only observables such as energy values there quanta but the involved physical fields, for instance
               the electromagnetic field, itself were described in an analogous fashion.
               Also special relativity was integrated into the theories, being called quantum field theories (QFT).
               </li>

               <li>
               The most accurate physical theory is Quantum Electro Dynamics (QED). Let us remember that by Maxwell a changing electrical field causes a magnetic moment.
               For an electron its angular mechanical momentum comes from two types of rotation: its orbital motion around the nucleus spin and it's spin,
               the rotation through its own axis so-to-speak. According to a quantum mechanical law,  Pauli exclusion principle, two ore more electrons
               cannot occupy the same quantum state. Thus electrons on the same shell must differ by spin (one up and one down corresponding to left- and right-rotation
               also the axis ) and other quantum numbers. This gives rise to the different chemical elements. But QED went a step further.
               Not only is is possibly to give basic quantitative and qualitative result, but also results with stunningly accuracy for instance the electron's magnetic moment.
               </li>
               </ul>

</div>

<br/><br/><button class="accordion">Symmetries and gauge theories</button>
<div class="panel">
<ul>
<li>
In the 1910ies Noether could prove that if a system has a continuous symmetry property, then there are corresponding quantities whose values are conserved in time. Many powerful theories in physics are invariant under some symmetry transformations. For instance , if a physical process exhibits the same outcomes regardless of place or time, then it's theory is symmetric under continuous translations in space and time. By Noether's theorem, these symmetries account for the conservation laws of momentum and energy.
<br/><br/>
When a system is invariant under a transformation identically performed at every point in the space it is said to global symmetric. Local symmetry is a stricter constraint. In fact, a global symmetry is just a local symmetry whose group's parameters are fixed in spacetime (the same way a constant value can be understood as a function of a certain parameter, but which output is always the same).
Local symmetry has important impact from a point of interpretation: The physical field under description can be thought itself as being necessary to ensure invariance. For instance QED seems to have a local symmetry with symmetry group U(1) and the according field is the electromagnetic one and the according particle is the photon.
<br/><br/>
Such local symmetric theories are called 'gauge theories' for historical reasons: The field resp. potential has to added to the 'energy function' description the system in order to ensure symmetry, it has to be gauged so-to-speak. In QED the symmetry group is the unitary group of degree one, U(1), also called the circle group, as it is the (multiplicative) group of all complex numbers with value 1.
The circle group is abelian: This means that carrying out two operations in reverse order gives the same result. If you turn the minute dial of your clock by 10 minutes clockwise and then 20 minutes clockwise it will be the same as the other way round.
<br/><br/>
Remember Coulomb laws: It stated that the force between two electrons decreases when the distance increases. This is the typical behavior of many forces for instance the gravitational one and is pretty intuitive.
</li>
</ul>
</div>



<br/><br/><button class="accordion">Quantum chromodynamics</button>
<div class="panel">
            We now come to a force with shows a stunning distinct behavior: It increases with distance like a string. Its is called the strong force. It can be not
explored in everyday's life: You need a computer program to carry out thought experiments and a particle accelerator like CERN's to verify them in real-life.
That's where SeekYou2 comes into play: Run the thought experiment on your mobile device and compare with experimental data published by CERN.

We have learned that electrons orbit nuclei to form atoms. But are they themselves elemental? For now the answer is yes. And the nucleus itself? No, it consists of protons (positively charged) and neutrons (neutral). Hmm … and the protons for instance, are they in turn elemental? NO. The seem have constituents being called quarks. The are 'glued' together by the gluons of the strong force.

So why does this force differ from the others? How are you sure that there are quarks? And how can  does an according calculation work? Let me wet your appetite before going into detail: The distinct behavior has just symmetry reasons, the according gauge group is not ableian. The string tension is enormous: some tons per pair of quarks. The computer program works essential as follows: In 19xx Wilson could show using a very clever argumentation that the complicated field equations could also be described by a thermodynamic system, a quark-gluon-soup so-to-speak which can be annealed in a computer simulation yielding physically relevant results. In a quantitative and qualitative sense.
</div>


<br/><br/><button class="accordion">The strong force on the lattice</button>
<div class="panel">
__program description__

So what this about? It might my a game, it might be directed directed by 'god'? Nevertheless it should suggested to work by itself! Gather your ideas and make  a better proposal! We are left now for a a solution to take our experience and our creativity. We have to find some idea fitting our  goal to understand this physics , which might be wrong, but has the the power of explaining.
The solution to this problem is crucial: Symmetry is essential. If the -god or nature-given symmetry-given symmetry holds -as a primary principle- the conclusion is straightforward: There should be a force for this.

With this belief we can proceed to explore. We have an idea and experiments that some particles are elementary whilst others are not. We have a governance by observation and might believe in this. What is  missing yet is concrete a technique to proceed. This idea was developed by two people. Richard Feyman took an adventure telling us, that solutions are more important than problems: The solutions has to be not in contradiction  with the problem itself: Just take the flavor of the solution, takes it's taste and lean back.
Lean back because someone else will find a specialized response to this universal way of thinking. This man was Wilson: He took Feyman's idea, that a physical system can per-se folllow take all possibilities at at disposal, but is essentially limited to preferred states. Through very smart reasoning he could argue that the strong force exhibits not only exhibits not only this behavior but can be mapped to a to a system to long known before: a thermodynamical one. For those systems sophisticated numerical methods has been invented by solid-state-physics especially by the solid-state-physician XXX. So now those stochastical simulations -invented in the 50ies- could be put onto the state-of-the-art computers of the 80ies buy Creutz. The results were astonishing: they could explain the string-like behavior of the strong force in accordance with the experiments.

Delegating to super-computers opened a new area: Yet even through heavy-wight simulations the machines can only approximate/describe the desired results of the theories. Also experiments showed that the involved theories cannot only explain part of the truth. Nature eventually cannot be put into terms 'quantized', 'digital',  'analogous' or whatever. But it deserves our need for investigation of it's beauty and should always involves the modesty of mankind.
</div>

<br/><br/><button class="accordion">How does SeekYouToo work?</button>
<div class="panel">
TODO
</div>

<br/><br/><button class="accordion">How do i use SeekYouToo?</button>
<div class="panel">
TODO
</div>

<br/><br/><button class="accordion">Results of the calculations</button>
<div class="panel">
TODO
</div>

<br/><br/><button class="accordion">How well do the results fit the physical reality as measured in particle accelerators?</button>
<div class="panel">
TODO
</div>

<br/><br/><button class="accordion">Further reading</button>
<div class="panel">
TODO
</div>

</div>


<script>
var acc = document.getElementsByClassName("accordion");
var i;

for (i = 0; i < acc.length; i++) {
  acc[i].addEventListener("click", function() {
    this.classList.toggle("active");
    var panel = this.nextElementSibling;
    if (panel.style.display === "block") {
      panel.style.display = "none";
    } else {
      panel.style.display = "block";
    }
  });
}
</script>


</body>
</html>
)Foo");


    QFile file(QString(":/docs/docs/foo.svg"));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString text;


    text = in.readAll();
    file.close();

    result.replace(QString("[svg]"),text);

    return result;

}

QQuickView *MainWindow::testWeb()
{
    QQuickView* result=new QQuickView();
    result->setVisible(true);
    result->setSource(QUrl("qrc:docs/docs/browserWidget.qml"));
    result->setProperty("foo",QString("http://www.google.com"));

    QQmlContext *localRootContext = result->rootContext();
    localRootContext->setContextProperty(QStringLiteral("url"),QStringLiteral("http://www.google.com"));


//    QQmlProperty foo(localRootContext,"url");
//    QVariant localRead = foo.read();
//    foo.write(QVariant::fromValue(QString("http://google.com")));

    //result->setProperty("url",QString("http://google.com"));



    QString msg = "http://edwin-roth.at/downloads/seekYouToo/docs/workman/workmanGuide.html";

    QMetaObject::invokeMethod(result->rootObject(), "setUrl",
            //Q_RETURN_ARG(QString, returnedValue),
            Q_ARG(QString, msg));


    //result->setColor(QColor(255,0,0));


    result->setResizeMode(QQuickView::SizeRootObjectToView);
    return result;
}


