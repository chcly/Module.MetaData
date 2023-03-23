set(TargetGroup Units/Transform)

set(TargetName Source)
add_subdirectory(${TargetName})

set(TargetName Transformer)
add_subdirectory(${TargetName})

set(TargetName Destination)
add_subdirectory(${TargetName})

