const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
body {
    background-color: white;
    color: black;
    width: 40pc;
    padding: 5px;
}
.wrapper {
    display: block;
    border: 2px solid #999;
    padding: 5px;
}
.mytop {
    align-items: center;
    padding: 25px;
}
.sliderBox{
    width: 80%;
    align-items: center;
    display: inline-block;
    padding: 10px;
}
.oneSlider{
    padding: 25px;
}
.posNegBtns{
    display: inline;
    padding: 2px;
}
.sbar {
    width: 100%;
}
.slide {
    border: 2px solid #999;
    padding: 10px;
}
.fnBoutons {
    align-items: center;
    padding: 25px;
}
</style>
<body>
    <div class="wrapper">
        <div class="mytop">
            <select id="designation-dropdown" name="design" onchange="selectOnChange(this.value)"></select>
        </div>
        <div class="sliderBox">
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Delay Start (ms)</label>
                <div class="slide"><input class="sbar" id="delayStart" type="range" min="0" max="2000" step="100" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="delayStartVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="delayStartMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="delayStartPlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Rampe PWM (%)</label>
                <div class="slide"><input class="sbar" id="rampePWM" type="range" min="0" max="100" step="5" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="rampePWMVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="rampePWMMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="rampePWMPlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Speed Welding (mm/s)</label>
                <div class="slide"><input class="sbar" id="speedWelding" type="range" min="0" max="10" step="0.5" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="speedWeldingVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="speedWeldingMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="speedWeldingPlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Balayage (mm)</label>
                <div class="slide"><input class="sbar" id="balayage" type="range" min="0" max="2" step="0.1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="balayageVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="balayageMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="balayagePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Speed wire (mm/s)</label>
                <div class="slide"><input class="sbar" id="speedWire" type="range" min="0" max="20" step="1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="speedWireVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="speedWireMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="speedWirePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Pulse wire (mm)</label>
                <div class="slide"><input class="sbar" id="pulseWire" type="range" min="0" max="10" step="1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="pulseWireVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="pulseWireMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="pulseWirePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>

            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Retract wire (mm)</label>
                <div class="slide"><input class="sbar" id="retractWire" type="range" min="0" max="10" step="1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="retractWireVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="retractWireMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="retractWirePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Huitieme</label>
                <div class="slide"><input class="sbar" id="huitieme" type="range" min="0" max="10" step="1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="huitiemeVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="huitiemeMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="huitiemePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
            <!--pour ajouter des sliders-->
            <div class="oneSlider">
                <label>Neuvieme</label>
                <div class="slide"><input class="sbar" id="neuvieme" type="range" min="0" max="10" step="1" value="0"
                        onchange="getSlider(this.id, this.value)"></div>
                <div class="slide">
                    <div id="neuviemeVal"></div>
                </div>
                <div class="posNegBtns">
                    <button id="neuviemeMoins" onclick="onMoins(this.id)">(-)</button>
                    <button id="neuviemePlus" onclick="onPlus(this.id)">(+)</button>
                </div>
            </div>
        </div>
    </div>
    <div class="fnBoutons">
        <button id="saveRegs" onclick="saveReglages()">Save</button>
        <button id="expJson" onclick="exportJson()">Exporter Un Json</button>
    </div>
    </div>
    <script>
    /**
 * 
 * global vars
 */
// json entier (données = data)
let data;
// au début on fabrique selector, ce vars rassure qu'il n'ai fabriqué qu'une fois et après, first = false
let first = true;

// indice actuel, 0 corréspond à D1_Eco 50, 1 corréspond à D2_Janisol
let projAct;
let projLen = 0;
let projNom = "projet";

// les noms des params de chaque json
// paramA[0] = "delayStart"
let paramA = [];
// len = 9, du 0 au 8 chaque boucle de var "i"
let len;
// du gui, on va remplir ça une fois avec step, min, max
let sliderA = [];
let url;

/**
 * ALWAYS update gui from data
 * 
 */

function guiUpdate() {

  // m-à-j gui des données
  for (let i = 0; i < len; i++) {
    // nom, comme "balayage"
    let param = paramA[i];
    // sa valeur il faut forcer Number() sinon il est traité comme texte (String)
    let val = Number(data[projAct][param]);

    // il faut chercher de nouveau chaque slider
    let s = document.getElementById(param);
    // et sa valeur montrée
    let sv = document.getElementById(param + "Val");

    // les boutons plus et moins, puisque on change leurs états en fonction de min max
    let bp = document.getElementById(param + "Plus");
    let bm = document.getElementById(param + "Moins");

    // update gui
    sv.innerHTML = s.value = val;

    // l'expression après = on simule le prochain appuis sur + ou - , et s'il sera trop grand ou petit, on désactive le bouton
    bp.disabled = val + Number(sliderA[i].step) > Number(sliderA[i].max);
    bm.disabled = val - Number(sliderA[i].step) < Number(sliderA[i].min);
  }
}

/**
 * populate select option w json
 * https://www.codebyamir.com/blog/populate-a-select-dropdown-list-with-json
 */
function setupGui() {
  // fabrique une fois seulement
  if (!first) return;

  let option;
  projLen = 0;
  // il n'y a qu'un seul selector
  let dropdown = document.getElementById('designation-dropdown');
  // initialiser
  removeAllChildNodes(dropdown);
  dropdown.length = 0;
  dropdown.selectedIndex = 0;
  // remplir selector
  for (const i in data) {
    option = document.createElement('option');
    option.text = data[i].nom;
    option.value = projNom + data[i].id;
    dropdown.add(option);
    projLen++;
  }

  // fill param key array, il y aura tjs un projet
  projAct = "projet1";
  // capter les noms de parametres dans un tableau
  paramA = Object.keys(data[projAct]);
  // supprimer "id" et "name"
  paramA.splice(0, 2);
  // capter pour boucler maj gui
  len = paramA.length;

  // remplir global var pour gérer le gui
  for (let i = 0; i < len; i++) {
    let s = document.getElementById(paramA[i]);
    let obj = {
      step: s.step,
      min: s.min,
      max: s.max
    };
    // step, min, max de chaque slider
    sliderA.push(obj);
  }

  // une fois seulement (on appel le json à chaque appuis sur selector)
  first = false;
}

/**
 * selector onChange()
 * https://www.w3schools.com/jsref/event_onchange.asp
 * 
 * Pulldown = selector
 */
function selectOnChange(curSelVal) {
  // capter l'projAct = l'indice actuel du json (un groupe de valeurs)
  for (const i in data) {
    let t = projNom + data[i].id;
    if (t == curSelVal) {
      // trouvé !
      projAct = t;
      break;
    }
  }
  // rechercher le json de nouveau à chaque appuis du selector
  url = 'reglages.json';
  request.open('GET', url, true);
  request.send();
}


/**
* slider onChange() -- si tu appuis sur un slider, on m-à-j les données
* https://stackoverflow.com/questions/13896685/html5-slider-with-onchange-function
*/
function getSlider(id, newVal) {
  for (let i = 0; i < len; i++) {
    // recherche dans tous les params (balayage, speed, etc)
    let param = paramA[i];
    // param touché
    if (id == param) {
      // nouvelle valeur du slider, ça vient du gui
      data[projAct][param] = Number(newVal);
      break;
    }
  }
  // update gui
  guiUpdate();
}


/**
* boutons plus et moins
* https://stackoverflow.com/questions/34156282/how-do-i-save-json-to-local-text-file
*/
function onPlus(monId) {
  for (let i = 0; i < len; i++) {
    // scan params
    let param = paramA[i];
    // identifier le bouton touché
    if (monId.includes(param)) {
      let n = Number(data[projAct][param]);
      // ajoute step à la valeur actuelle
      n += Number(sliderA[i].step);
      // m-à-j les données
      data[projAct][param] = n.toFixed(2);
      break;
    }
  }
  // update gui -- toujours les données conduisent le gui !!!
  guiUpdate();
}
function onMoins(monId) {
  for (let i = 0; i < len; i++) {
    // scan params
    let param = paramA[i];
    // update param of touched slider
    if (monId.includes(param)) {
      let n = Number(data[projAct][param]);
      n -= Number(sliderA[i].step);
      data[projAct][param] = n.toFixed(2);
      break;
    }
  }
  // update gui
  guiUpdate();
}

/**
* save json to file
* https://stackoverflow.com/questions/34156282/how-do-i-save-json-to-local-text-file
*/
function saveReglages() {
  var a = document.createElement("a");
  let pkg = JSON.stringify(data);
  var file = new Blob([pkg], { type: 'text/plain' });
  a.href = URL.createObjectURL(file);
  a.download = 'reglages.json';
  a.click();
}

function exportJson() {
  var a = document.createElement("a");
  let pkg = JSON.stringify(data[projAct]);
  var file = new Blob([pkg], { type: 'text/plain' });
  a.href = URL.createObjectURL(file);
  a.download = data[projAct]["nom"]+'.json';
  a.click();
}

function removeAllChildNodes(parent) {
  while (parent.firstChild) {
      parent.removeChild(parent.firstChild);
  }
}
// 

const request = new XMLHttpRequest();
request.open("GET", "my_json", true);

request.onreadystatechange = function () {
  if (this.readyState == 4 && request.status === 200) {
    // c'est bon
    data = JSON.parse(request.responseText);
    // remplir selector
    setupGui();
  } else {
    // Reached the server, but it returned an error
  }
  // initial
  guiUpdate();
}
request.onerror = function () {
  console.error('An error occurred fetching the JSON from ' + url);
};

// c'est parti -- premier appel à une fonction
request.send();
    </script>
</body>
</html>
)=====";
