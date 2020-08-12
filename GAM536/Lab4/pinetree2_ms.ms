
function drawPineTree numCones treeColour = (
	coneRadius = 25*numCones
	for i = 1 to numCones do(
		cone pos:[0,0,(i-1)*100] height: 100 radius1:coneRadius wirecolor:treeColour
		coneRadius = coneRadius-25
	)
)

function main = (
	delete objects
	drawPineTree(5)
)

--main()
--we don't need main() fuction because when we run the dialog then it will call the drawPineTree() function

try(destroyDialog myUIExample )catch()
rollout myUIExample "Pine Tree Creator" (
	group "Controls" (
		spinner numSegmentsSpinner "Number of Segments:" type:#integer range:[1,10,3]
		colorpicker treeColourPicker "Tree Colour:"
		button createBoxButton "Generate Pine Tree"
	)
	on createBoxButton pressed do(
		drawPineTree numSegmentsSpinner.value treeColourPicker.color
	)
)
createDialog myUIExample 300 300