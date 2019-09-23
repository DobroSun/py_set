.PHONY: clear upload


upload:
	echo "Uploading"

clear: 
	docker container prune -f
	docker images --filter "dangling=true" -q | xargs docker rmi

