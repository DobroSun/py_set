.PHONY: clear upload


upload:
	rm -rf dist
	python3 setup.py sdist
	twine upload dist/*

clean:
	docker container prune -f
	docker images --filter "dangling=true" -q | xargs docker rmi

