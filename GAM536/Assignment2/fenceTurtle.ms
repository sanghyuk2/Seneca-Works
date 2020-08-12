function picketFence start direction numSeg fenceColour = (
	
	position = start
	rotationQuat = quat direction [0,0,1]
	invq = inverse rotationQuat
	heading = [1,0,0]*invq

	post1 = box wirecolor:fenceColour length:5 width:5 height:40

	bottomPlank = box pos:[0,0,5] wirecolor:fenceColour length:2 width:60 height:5
	move post1 position
	rotate post1 rotationQuat
	
	move bottomPlank (position)
	rotate bottomPlank rotationQuat
	move bottomPlank (30*heading)


)

function main=(
	delete objects
	picketFence [0,0,0] 0 2 blue
	picketFence [20,20,0] 45 3 green
	picketFence [0,0,0] 120 2 red
)
main()