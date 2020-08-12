
function drawCones numCones = (
	
	coneRadius = 25*numCones
	for i = 1 to numCones do(
		cone pos:[0,0,(i-1)*100] height: 100 radius1:coneRadius
		coneRadius = coneRadius-25
	)
)

function main = (
	delete objects
	drawCones(5)
)

main()